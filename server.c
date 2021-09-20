/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:20:59 by user42            #+#    #+#             */
/*   Updated: 2021/09/20 14:05:13 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


#include <stdio.h>

static void	send_sig(pid_t pid, int sig)
{
	int	kill_exec;

	kill_exec = kill(pid, sig);
	if (kill_exec == -1)
		error("error while sending AR");
}

static void	ft_action(int sig_num, siginfo_t *info, void *context)
{
	static char		c = 0xFF;
	static int		bit = 0;
	static pid_t	pid = 0;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (sig_num == SIGUSR2)
		c = c | (0x80 >> bit);
	else if (sig_num == SIGUSR1)
		c = c ^ (0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
//			ft_putstr_fd("null received - send sig2\n", 1);
			send_sig(pid, SIGUSR2);
			c = 0xFF;
			bit = 0;
			pid = 0;
			return ;
		}
		write(1, &c, 1);
		c = 0xFF;
		bit = 0;
	}
	send_sig(pid, SIGUSR1);
}
	

int	main(int argc, char **argv)
{
	int					pid;
	char				*pid_str;
	struct sigaction	action;

	if (argc != 1)
		error("no arguments needed");
	(void)argv;
	action.sa_sigaction = ft_action;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid = getpid();
	pid_str = ft_itoa(pid);
	ft_putstr_fd(pid_str, 1);
	free(pid_str);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
