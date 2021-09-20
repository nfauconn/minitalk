/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_sig_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:20:59 by user42            #+#    #+#             */
/*   Updated: 2021/09/19 18:30:14 by user42           ###   ########.fr       */
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

/*static char	*init_buff(char c)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 2);
	if (!buff)
		exit(EXIT_FAILURE);
	buff[0] = c;
	buff[1] = '\0';
	return (buff);
}*/

//static void	fill_buff(char **buff, char c, pid_t pid, int kill_exec)
static void	display(char c, pid_t pid, int kill_exec)
{
/*	if (!*buff)
		*buff = init_buff(c);
	else
		*buff = strfjoinchar(*buff, c);
*/	write(1, &c, 1);
	if (c == 0)
	{
//		ft_putstr_fd(*buff, 1);
//		free(*buff);
//		*buff = NULL;
		kill_exec = kill(pid, SIGUSR2);
		if (kill_exec == -1)
			error("error while sending AR\n");
//			error_server("error while sending AR\n", buff);
		usleep(100);
	}
}



static void	ft_action(int sig_num, siginfo_t *info, void *context)
{
	static char		c = 0xFF;
	static int		bits = 0;
	static pid_t	pid = 0;
	static char		*buff;
	int				kill_exec;

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
//		fill_buff(&buff, c, pid, kill_exec);
		display(c, pid, kill_exec);
		c = 0xFF;
		bits = 0;
		kill(pid, SIGUSR1);
//		kill_exec = kill(pid, SIGUSR1);
//		if (kill_exec == -1)
//			error("error while sending AR\n");
//			error_server("error while sending AR\n", &buff);
		usleep(100);
	}
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
