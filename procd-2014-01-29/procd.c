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

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <getopt.h>
#include <libgen.h>

#include "procd.h"
#include "watchdog.h"
#include "plug/hotplug.h"

unsigned int debug;

static int usage(const char *prog)
{
	ERROR("Usage: %s [options]\n"
		"Options:\n"
		"\t-s <path>\tPath to ubus socket\n"
		"\t-h <path>\trun as hotplug daemon\n"
		"\t-d <level>\tEnable debug messages\n"
		"\n", prog);
	return 1;
}

int main(int argc, char **argv)//内核发生热插拔时会执行一次/proc/sys/kernel/hotplug。
{///sbin/mdev > /proc/sys/kernel/hotplug，本质上内核发生一次热插拔时执行一次/sbin/mdev
	int ch;
	char *dbglvl = getenv("DBGLVL");

	if (dbglvl) {
		debug = atoi(dbglvl);
		unsetenv("DBGLVL");
	}

	while ((ch = getopt(argc, argv, "d:s:h:")) != -1) {
		switch (ch) {
		case 'h':
			return hotplug_run(optarg);//执行hotplug_run(/etc/hotplug-preinit.json):
		case 's':
			ubus_socket = optarg;
			break;
		case 'd':
			debug = atoi(optarg);
			break;
		default:
			return usage(argv[0]);
		}
	}
	uloop_init();
	procd_signal();
	trigger_init();
	if (getpid() != 1)
		procd_connect_ubus();
	else
		procd_state_next();//进程pid=1才执行procd_state_next，这才是开机启动流程中的procd，负责解析/etc/inittab文件并据此依次启动系统。
	uloop_run();

	return 0;
}
