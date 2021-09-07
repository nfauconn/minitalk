/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:11:48 by leo               #+#    #+#             */
/*   Updated: 2021/09/07 17:55:59 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	get_pid(char *nb)
{
	pid_t	pid;

	if (!str_isdigit(nb))
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = ft_atoi(nb);
	if (pid <= 0 || pid > 32768)
		error("wrong PID");
	return (pid);
}

void	send_signals(char *message, pid_t pid)
{
	int		i;
	int		kill_exec;
	int		bitshift;
	int		comparator;

	i = 0;
	bitshift = -1;
	while (message[i])
	{
		while (++bitshift < 8)
		{
			comparator = 0x80 >> bitshift;
			if (message[i] & comparator)
			{
				kill_exec = kill(pid, SIGUSR2);
				if (kill_exec == -1)
					error("an error occured while sending signal\nplease verify PID");
			}
			else
			{
				kill_exec = kill(pid, SIGUSR1);
				if (kill_exec == -1)
					error("an error occured while sending signal\nplease verify PID");
			}
			usleep(3);
		}
		i++;
		bitshift = -1;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = get_pid(argv[1]);
	send_signals(argv[2], pid);
	ft_printf("\nmessage sent successfully\n\n");
	return (0);
}
