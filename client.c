
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:21:34 by user42            #+#    #+#             */
/*   Updated: 2021/09/19 17:51:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
uint64_t micros() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec*(uint64_t)1000000+tv.tv_usec;
}
uint64_t t1;
uint64_t t2;

t_infos	g = {NULL, 0, 0, 0, 0, 0};


pid_t	get_pid(char *nb)
{
	pid_t	pid;

	if (!str_isdigit(nb))
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = ft_atoi(nb);
	return (pid);
}

static void	send_sig(pid_t pid, int sig)
{
	int	kill_exec;

	kill_exec = kill(pid, sig);
	if (kill_exec == -1)
		error("error while sending signal\nplease verify PID");
}

static void	send_first_signal(pid_t pid)
{
	g.comparator = 0x80 >> g.bitshift;
	if (g.message[g.i] & g.comparator)
		send_sig(pid, SIGUSR2);
	else
		send_sig(pid, SIGUSR1);
}

static void	handler(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		if (!g.message[g.i])
		{
			ft_putstr_fd("send null\n", 1);
			while (++g.bitshift <= 8)
			{
				printf("send null bit %d\n", g.bitshift);
				send_sig(g.pid, SIGUSR1);
				return ;
			}
		}
		else
		{
			if (++g.bitshift >= 8)
			{
				g.i++;
				g.bitshift = 0;
			}
			g.comparator = 0x80 >> g.bitshift;
			if (g.message[g.i] & g.comparator)
				send_sig(g.pid, SIGUSR2);
			else
				send_sig(g.pid, SIGUSR1);
		}
	}
	if (sig_num == SIGUSR2)
	{
		ft_putstr_fd("\n\nmessage sent successfully\n\n", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3)
		error("wrong arguments\nformat : ./client <PID> <message>");
	g.pid = get_pid(argv[1]);
	g.message = argv[2];
	action.sa_handler = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_first_signal(g.pid);
	while (1)
	{
//		ft_putstr_fd("\npause...\n", 1);
		pause();
	}
	return (0);
}

//	printf("t1: %ld\n", t1);
