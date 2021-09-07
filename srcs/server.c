/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/07 17:46:43 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//https://github.com/mlanca-c/Minitalk/wiki/Projecct#1st-step-make-server-receive-a-signal-from-client

void	signal_handler(int sig_num)
{
	static char	c = 255;
	static int	bits = 0;

	if (sig_num == SIGUSR2)
		c = c | (0x80 >> bits);
	else if (sig_num == SIGUSR1)
		c = c ^ (0x80 >> bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		c = 255;
		bits = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_act;

	if (argc != 1)
		error("no arguments needed");
	(void)argv;
	ft_printf("%d\n", getpid());
    sigemptyset(&sig_act.sa_mask);
    sig_act.sa_handler = signal_handler;
    sig_act.sa_flags = 0;
    sigaction(SIGUSR1, &sig_act, NULL);
    sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
		pause();
	free(&sig_act);
	return (0);
}
