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

#include <sys/time.h>
#include <unistd.h>

#include "libubus.h"

static struct ubus_context *ctx;
static struct blob_buf b;

static void test_client_subscribe_cb(struct ubus_context *ctx, struct ubus_object *obj)
{
	fprintf(stderr, "Subscribers active: %d\n", obj->has_subscribers);
}

static struct ubus_object test_client_object = {
	.subscribe_cb = test_client_subscribe_cb,
};//struct ubus_object中包含该object的id、path及描述信息成员函数subscribe_cb，名称name及ubus方法ubus_method

static void test_client_notify_cb(struct uloop_timeout *timeout)
{
	static int counter = 0;
	int err;
	struct timeval tv1, tv2;
	int max = 1000;
	long delta;
	int i = 0;

	blob_buf_init(&b, 0);
	blobmsg_add_u32(&b, "counter", counter++);

	gettimeofday(&tv1, NULL);
	for (i = 0; i < max; i++)
		err = ubus_notify(ctx, &test_client_object, "ping", b.head, 1000);
	gettimeofday(&tv2, NULL);
	if (err)
		fprintf(stderr, "Notify failed: %s\n", ubus_strerror(err));

	delta = (tv2.tv_sec - tv1.tv_sec) * 1000000 + (tv2.tv_usec - tv1.tv_usec);
	fprintf(stderr, "Avg time per iteration: %ld usec\n", delta / max);

	uloop_timeout_set(timeout, 1000);
}

static struct uloop_timeout notify_timer = {
	.cb = test_client_notify_cb,
};

static void client_main(void)
{
	uint32_t id;
	int ret;

	ret = ubus_add_object(ctx, &test_client_object);//将该object中的path method方法 id等信息通过ctx中的套接字发给ubusd(/var/run/ubus.sock)。
	if (ret) {
		fprintf(stderr, "Failed to add_object object: %s\n", ubus_strerror(ret));
		return;
	}

	if (ubus_lookup_id(ctx, "test", &id)) {//在ubusd中查找path为test的object(通过ctx中的套接字var/run/ubus.sock向ubusd发送查找请求??)
		fprintf(stderr, "Failed to look up test object\n");
		return;
	}

	blob_buf_init(&b, 0);
	blobmsg_add_u32(&b, "id", test_client_object.id);
	ubus_invoke(ctx, id, "watch", b.head, NULL, 0, 3000);//向ubusd发送服务请求，请求调用path为test的object的watch方法-->ubusd收到请求后通过var/run/ubus.sock想提供服务的进程发送消息??
	test_client_notify_cb(&notify_timer);
	uloop_run();
}

int main(int argc, char **argv)
{
	const char *ubus_socket = NULL;
	int ch;

	while ((ch = getopt(argc, argv, "cs:")) != -1) {//表示只有一个选项，不是c就是s。
		switch (ch) {
		case 's':
			ubus_socket = optarg;//optarg指向-xx选项后面的参数
			break;
		default:
			break;
		}
	}

	argc -= optind;//optind表示第几个选项(在所有选项中的序号)
	argv += optind;

	uloop_init();

	ctx = ubus_connect(ubus_socket);//该客户端例程类似ubus命令。此处可更改本例程向ubusd后台发送请求的套接字路径。
	if (!ctx) {
		fprintf(stderr, "Failed to connect to ubus\n");
		return -1;
	}

	ubus_add_uloop(ctx);

	client_main();

	ubus_free(ctx);
	uloop_done();

	return 0;
}
