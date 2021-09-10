/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/10 14:05:29 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*init_buff(char c)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 2);
	if (!buff)
		exit(EXIT_FAILURE);
	buff[0] = c;
	buff[1] = '\0';
	return (buff);
}

static void	signal_handler(int sig_num, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*buff;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig_num == SIGUSR2)
		c = c | (0x80 >> bits);
	else if (sig_num == SIGUSR1)
		c = c ^ (0x80 >> bits);
	bits++;
	if (bits == 8)
	{
		if (!buff)
			buff = init_buff(c);
		else
			buff = strfjoinchar(buff, c);
		if (!c)
		{
			ft_printf("%s", buff);
			buff = NULL;
			free(buff);
		}
		c = 0xFF;
		bits = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
/*	struct sigaction	sig_act;
	sigset_t 			block_mask;


	if (argc != 1)
		error("no arguments needed");
	(void)argv;
	ft_printf("PID : %d\n", getpid());
	sig_act.sa_handler = signal_handler;
	sig_act.sa_mask = block_mask;
	sig_act.sa_flags = SIGINFO;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
		pause();
*/
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	if (argc != 1)
		error("no arguments needed");
	(void)argv;
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
}
