/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:21:34 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/27 15:54:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_infos	g_infos = {NULL, 0, 0, 0};

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
	if (g_infos.message[g_infos.i] & 0x80 >> g_infos.bitshift)
		send_sig(pid, SIGUSR2);
	else
		send_sig(pid, SIGUSR1);
}

static void	handler(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		if (!g_infos.message[g_infos.i])
		{
			if (++g_infos.bitshift <= 8)
				send_sig(g_infos.pid, SIGUSR1);
		}
		else
		{
			if (++g_infos.bitshift >= 8)
			{
				g_infos.i++;
				g_infos.bitshift = 0;
			}
			if (g_infos.message[g_infos.i] & 0x80 >> g_infos.bitshift)
				send_sig(g_infos.pid, SIGUSR2);
			else
				send_sig(g_infos.pid, SIGUSR1);
		}
	}
	else if (sig_num == SIGUSR2)
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
	g_infos.pid = get_pid(argv[1]);
	g_infos.message = argv[2];
	action.sa_handler = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_first_signal(g_infos.pid);
	while (1)
		pause();
	return (0);
}
