/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:26 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/04 15:52:38 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error()
{
	ft_printf("\nwrong arguments\nformat : ./client <PID> <string_to_display>\n\n");
	exit(EXIT_FAILURE);
}

pid_t	get_pid(char *str)
{
	pid_t	pid;

	if (!str_isdigit(str))
		error();
	pid = ft_atoi(str);
	return (pid);
}

void	send_signal(pid_t pid, char *to_display)
{
	int	i;
	int	c;

	if (!to_display)
		error();
	while (*to_display)
	{
		i = 0;
		c = *to_display;
		while (i < 8)
		{
			if (c & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			c = c >> 1;
			usleep(100);
			i++;
		}
		to_display++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*to_display;

	if (argc != 3)
		error();
	else
	{
		pid = get_pid(argv[1]);
		to_display = argv[2];
		send_signal(pid, to_display);
	}
	return (0);
}
