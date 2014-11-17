/*
 * Copyright (C) 2011 Felix Fietkau <nbd@openwrt.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1
 * as published by the Free Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <libubox/blob.h>
#include <libubox/uloop.h>
#include <libubox/usock.h>
#include <libubox/list.h>

#include "ubusd.h"

static struct ubus_msg_buf *ubus_msg_unshare(struct ubus_msg_buf *ub)
{
	ub = realloc(ub, sizeof(*ub) + ub->len);
	if (!ub)
		return NULL;

	ub->refcount = 1;
	memcpy(ub + 1, ub->data, ub->len);
	ub->data = (void *) (ub + 1);
	return ub;
}

static struct ubus_msg_buf *ubus_msg_ref(struct ubus_msg_buf *ub)
{
	if (ub->refcount == ~0)
		return ubus_msg_unshare(ub);

	ub->refcount++;
	return ub;
}

struct ubus_msg_buf *ubus_msg_new(void *data, int len, bool shared)
{
	struct ubus_msg_buf *ub;
	int buflen = sizeof(*ub);

	if (!shared)
		buflen += len;

	ub = calloc(1, buflen);
	if (!ub)
		return NULL;

	if (shared) {
		ub->refcount = ~0;
		ub->data = data;
	} else {
		ub->refcount = 1;
		ub->data = (void *) (ub + 1);
		if (data)
			memcpy(ub + 1, data, len);
	}

	ub->len = len;
	return ub;
}

void ubus_msg_free(struct ubus_msg_buf *ub)
{
	switch (ub->refcount) {
	case 1:
	case ~0:
		free(ub);
		break;
	default:
		ub->refcount--;
		break;
	}
}

static int ubus_msg_writev(int fd, struct ubus_msg_buf *ub, int offset)
{
	struct iovec iov[2];

	if (offset < sizeof(ub->hdr)) {
		iov[0].iov_base = ((char *) &ub->hdr) + offset;
		iov[0].iov_len = sizeof(ub->hdr) - offset;
		iov[1].iov_base = (char *) ub->data;
		iov[1].iov_len = ub->len;
		return writev(fd, iov, 2);
	} else {
		offset -= sizeof(ub->hdr);
		return write(fd, ((char *) ub->data) + offset, ub->len - offset);
	}
}

static void ubus_msg_enqueue(struct ubus_client *cl, struct ubus_msg_buf *ub)
{
	if (cl->tx_queue[cl->txq_tail])
		return;

	cl->tx_queue[cl->txq_tail] = ubus_msg_ref(ub);
	cl->txq_tail = (cl->txq_tail + 1) % ARRAY_SIZE(cl->tx_queue);
}

/* takes the msgbuf reference */
void ubus_msg_send(struct ubus_client *cl, struct ubus_msg_buf *ub, bool free)
{
	int written;

	if (!cl->tx_queue[cl->txq_cur]) {
		written = ubus_msg_writev(cl->sock.fd, ub, 0);
		if (written >= ub->len + sizeof(ub->hdr))
			goto out;

		if (written < 0)
			written = 0;

		cl->txq_ofs = written;

		/* get an event once we can write to the socket again */
		uloop_fd_add(&cl->sock, ULOOP_READ | ULOOP_WRITE | ULOOP_EDGE_TRIGGER);
	}
	ubus_msg_enqueue(cl, ub);

out:
	if (free)
		ubus_msg_free(ub);
}

static struct ubus_msg_buf *ubus_msg_head(struct ubus_client *cl)
{
	return cl->tx_queue[cl->txq_cur];
}

static void ubus_msg_dequeue(struct ubus_client *cl)
{
	struct ubus_msg_buf *ub = ubus_msg_head(cl);

	if (!ub)
		return;

	ubus_msg_free(ub);
	cl->txq_ofs = 0;
	cl->tx_queue[cl->txq_cur] = NULL;
	cl->txq_cur = (cl->txq_cur + 1) % ARRAY_SIZE(cl->tx_queue);
}

static void handle_client_disconnect(struct ubus_client *cl)
{
	while (ubus_msg_head(cl))
		ubus_msg_dequeue(cl);

	ubusd_proto_free_client(cl);
	uloop_fd_delete(&cl->sock);
	close(cl->sock.fd);
	free(cl);
}

static void client_cb(struct uloop_fd *sock, unsigned int events)
{
	struct ubus_client *cl = container_of(sock, struct ubus_client, sock);
	struct ubus_msg_buf *ub;

	/* first try to tx more pending data */
	while ((ub = ubus_msg_head(cl))) {
		int written;

		written = ubus_msg_writev(sock->fd, ub, cl->txq_ofs);
		if (written < 0) {
			switch(errno) {
			case EINTR:
			case EAGAIN:
				break;
			default:
				goto disconnect;
			}
			break;
		}

		cl->txq_ofs += written;
		if (cl->txq_ofs < ub->len + sizeof(ub->hdr))
			break;

		ubus_msg_dequeue(cl);
	}

	/* prevent further ULOOP_WRITE events if we don't have data
	 * to send anymore */
	if (!ubus_msg_head(cl) && (events & ULOOP_WRITE))
		uloop_fd_add(sock, ULOOP_READ | ULOOP_EDGE_TRIGGER);

retry:
	if (!sock->eof && cl->pending_msg_offset < sizeof(cl->hdrbuf)) {
		int offset = cl->pending_msg_offset;
		int bytes;

		bytes = read(sock->fd, (char *)&cl->hdrbuf + offset, sizeof(cl->hdrbuf) - offset);
		if (bytes < 0)
			goto out;

		cl->pending_msg_offset += bytes;
		if (cl->pending_msg_offset < sizeof(cl->hdrbuf))
			goto out;

		if (blob_pad_len(&cl->hdrbuf.data) > UBUS_MAX_MSGLEN)
			goto disconnect;

		cl->pending_msg = ubus_msg_new(NULL, blob_raw_len(&cl->hdrbuf.data), false);
		if (!cl->pending_msg)
			goto disconnect;

		memcpy(&cl->pending_msg->hdr, &cl->hdrbuf.hdr, sizeof(cl->hdrbuf.hdr));
		memcpy(cl->pending_msg->data, &cl->hdrbuf.data, sizeof(cl->hdrbuf.data));
	}

	ub = cl->pending_msg;
	if (ub) {
		int offset = cl->pending_msg_offset - sizeof(ub->hdr);
		int len = blob_raw_len(ub->data) - offset;
		int bytes = 0;

		if (len > 0) {
			bytes = read(sock->fd, (char *) ub->data + offset, len);
			if (bytes <= 0)
				goto out;
		}

		if (bytes < len) {
			cl->pending_msg_offset += bytes;
			goto out;
		}

		/* accept message */
		cl->pending_msg_offset = 0;
		cl->pending_msg = NULL;
		ubusd_proto_receive_message(cl, ub);
		goto retry;
	}

out:
	if (!sock->eof || ubus_msg_head(cl))
		return;

disconnect:
	handle_client_disconnect(cl);
}

static bool get_next_connection(int fd)
{
	struct ubus_client *cl;
	int client_fd;

	client_fd = accept(fd, NULL, 0);
	if (client_fd < 0) {
		switch (errno) {
		case ECONNABORTED:
		case EINTR:
			return true;
		default:
			return false;
		}
	}

	cl = ubusd_proto_new_client(client_fd, client_cb);
	if (cl)
		uloop_fd_add(&cl->sock, ULOOP_READ | ULOOP_EDGE_TRIGGER);
	else
		close(client_fd);

	return true;
}

static void server_cb(struct uloop_fd *fd, unsigned int events)
{
	bool next;

	do {
		next = get_next_connection(fd->fd);
	} while (next);
}

static struct uloop_fd server_fd = {
	.cb = server_cb,
};

static int usage(const char *progname)
{
	fprintf(stderr, "Usage: %s [<options>]\n"
		"Options: \n"
		"  -s <socket>:		Set the unix domain socket to listen on\n"
		"\n", progname);
	return 1;
}

int main(int argc, char **argv)
{
	const char *ubus_socket = UBUS_UNIX_SOCKET;//定义在cmake中，UBUS_UNIX_SOCKET="/var/run/ubus.sock"
	int ret = 0;
	int ch;

	signal(SIGPIPE, SIG_IGN);//入参:信号类型；处理函数handler。

	uloop_init();

	while ((ch = getopt(argc, argv, "s:")) != -1) {
		switch (ch) {
		case 's':
			ubus_socket = optarg;
			break;
		default:
			return usage(argv[0]);
		}
	}

	unlink(ubus_socket);//unlink，删除/var/run/ubus.sock文件
	umask(0177);//umask,设置用户创建新文件时文件的默认权限。
	server_fd.fd = usock(USOCK_UNIX | USOCK_SERVER | USOCK_NONBLOCK, ubus_socket, NULL);
	if (server_fd.fd < 0) {//usock,首参为套接字类型，ubus_socket可为"127.0.0.1"或var/run/ubus.sock,最后一个为服务端口号"22"或NULL
		perror("usock");
		ret = -1;
		goto out;
	}
	uloop_fd_add(&server_fd, ULOOP_READ | ULOOP_EDGE_TRIGGER);

	uloop_run();//调用uloop_run()，ubusd进程不会再退出--->ubusd通过select方法监听套接字/var/run/ubus.sock，接收ubus发出的服务查询/请求，并将服务请求转发给netifd等提供服务的进程。
	unlink(ubus_socket);

out:
	uloop_done();
	return ret;
}
