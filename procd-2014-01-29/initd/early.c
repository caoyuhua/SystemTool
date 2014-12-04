/*
 * Copyright (C) 2013 Felix Fietkau <nbd@openwrt.org>
 * Copyright (C) 2013 John Crispin <blogic@openwrt.org>
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

#include <sys/mount.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "../log.h"
#include "init.h"

static void
early_mounts(void)
{
	mount("proc", "/proc", "proc", MS_NOATIME, 0);//Now system's filesystem is READ_ONLY squashfs(In kernel:rootfs-->squashfs)
	mount("sysfs", "/sys", "sysfs", MS_NOATIME, 0);//mount kernel�s procfs tmpfs sysfs on squashfs's dirctory of/proc /sys...,so we can read_write in /tmp /proc..
	mount("tmpfs", "/tmp", "tmpfs", MS_NOSUID | MS_NODEV | MS_NOATIME, NULL);
	mkdir("/tmp/run", 0777);
	mkdir("/tmp/lock", 0777);
	mkdir("/tmp/state", 0777);
	symlink("/tmp", "/var");//Ϊ/tmpĿ¼����һ�������ӵ�/varĿ¼������/tmpĿ¼���Ƿ���/varĿ¼��

	mount("tmpfs", "/dev", "tmpfs", MS_NOATIME, "mode=0755,size=512K");
	mkdir("/dev/shm", 0755);
	mkdir("/dev/pts", 0755);
	mount("devpts", "/dev/pts", "devpts", MS_NOATIME, "mode=600");
}//Next In /etc/preinit(/lib/preinit/*) and /etc/init.d/boot,we will call mount_root(fstools/mount_root.c) to do more operation about filesystem mounts.

static void
early_dev(void)
{
	mkdev("*", 0600);
	mknod("/dev/null", 0666, makedev(1, 3));//����1:�豸�ڵ������·�������ƣ�����Ȩ�ޣ�makedev���ں��д����豸�ļ�(���豸�ţ����豸��)
}///dev/null��һ�豸�ļ��ڴ˴�������/dev/console��һ�豸�ļ��ںδ�����??

static void
early_console(const char *dev)
{
	struct stat s;
	int dd;

	if (stat(dev, &s)) {//stat()����ȡ�ļ���״̬��Ϣ(linux��ls����Դ��ʹ��stat�����϶�)
		ERROR("Failed to stat %s\n", dev);
		return;
	}

	dd = open(dev, O_RDWR);
	if (dd < 0)
		dd = open("/dev/null", O_RDWR);

	dup2(dd, STDIN_FILENO);//dup2()��Ϊ�ļ������ֵ(�˴���linux�ı�׼�����׼��������ó�/dev/console�ļ�)
	dup2(dd, STDOUT_FILENO);
	dup2(dd, STDERR_FILENO);

	if (dd != STDIN_FILENO &&
	    dd != STDOUT_FILENO &&
	    dd != STDERR_FILENO)
		close(dd);
}

static void
early_env(void)
{
	setenv("PATH", "/bin:/sbin:/usr/bin:/usr/sbin", 1);//setenv,���û�������$PATH��ֵ��
}

void
early(void)
{
	if (getpid() != 1)//getpid()��ȡ��ǰ���̵�pid�ţ�1Ϊprocd���̵�pid�š�
		return;

	early_mounts();
	early_dev();
	early_env();
	early_console("/dev/console");

	LOG("Console is alive\n");
}
