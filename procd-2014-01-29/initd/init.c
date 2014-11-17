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
#include <sys/reboot.h>

#include <libubox/uloop.h>
#include <libubus.h>

#include <stdlib.h>
#include <fcntl.h>
#include <getopt.h>
#include <libgen.h>
#include <regex.h>
#include <unistd.h>
#include <stdio.h>

#include "init.h"
#include "../watchdog.h"

unsigned int debug = 0;

static void
signal_shutdown(int signal, siginfo_t *siginfo, void *data)
{
	fprintf(stderr, "reboot\n");
	fflush(stderr);
	sync();
	sleep(2);
	reboot(RB_AUTOBOOT);
	while (1)
		;
}

static struct sigaction sa_shutdown = {
	.sa_sigaction = signal_shutdown,
	.sa_flags = SA_SIGINFO
};

static void
cmdline(void)
{
	char line[256];
	int r, fd = open("/proc/cmdline", O_RDONLY);
	regex_t pat_cmdline;
	regmatch_t matches[2];

	if (fd < 0)
		return;

	r = read(fd, line, sizeof(line) - 1);
	line[r] = '\0';
	close(fd);

	regcomp(&pat_cmdline, "init_debug=([0-9]+)", REG_EXTENDED);
	if (!regexec(&pat_cmdline, line, 2, matches, 0)) {
		line[matches[1].rm_eo] = '\0';
		debug = atoi(&line[matches[1].rm_so]);
	}
	regfree(&pat_cmdline);
}

int
main(int argc, char **argv)//1.启动第一阶段：openwrt的init程序
{
	pid_t pid;

	sigaction(SIGTERM, &sa_shutdown, NULL);
	sigaction(SIGUSR1, &sa_shutdown, NULL);
	sigaction(SIGUSR2, &sa_shutdown, NULL);//sigaction，设置SIGUSR1等三个信号的处理函数为sa_shutdown(一旦捕获到这三个信号便会执行处理函数).

	early();//early.c中，主要挂载proc sys和tmpfs文件系统并将STDIN STDOUT文件句柄设置为/dev/console
	cmdline();
	watchdog_init(1);

	pid = fork();
	if (!pid) {
		char *kmod[] = { "/sbin/kmodloader", "/etc/modules-boot.d/", NULL };//kmodloader命令由ubox源码编译出来。

		if (debug < 3) {
			int fd = open("/dev/null", O_RDWR);

			if (fd > -1) {
				dup2(fd, STDIN_FILENO);
				dup2(fd, STDOUT_FILENO);
				dup2(fd, STDERR_FILENO);
				if (fd > STDERR_FILENO)
					close(fd);
			}
		}
		execvp(kmod[0], kmod);//execvp(),执行应用程序，第二个参数作为应用程序的入参(/etc/modules-boot.d/只有部分，还有/etc/modules.d在何处加载??)
		ERROR("Failed to start kmodloader\n");
		exit(-1);
	}
	if (pid <= 0)
		ERROR("Failed to start kmodloader instance\n");
	uloop_init();
	preinit();//内核先执行/sbin/init(/sbin/init即是本init.c编译而来)并在此处调preinit()(执行了/etc/preinit脚本；最后启动/sbin/procd)
	uloop_run();

	return 0;
}
