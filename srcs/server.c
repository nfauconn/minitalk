/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:30:08 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//https://github.com/mlanca-c/Minitalk/wiki/Projecct#1st-step-make-server-receive-a-signal-from-client

void	signal_handler(int sig_num)
{
	static char	c = 0xFF;
	static int	bits = 0;

	if (sig_num == SIGUSR2)
		c = c | (0x80 >> bits);
	else if (sig_num == SIGUSR1)
		c = c ^ (0x80 >> bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		c = 0xFF;
		bits = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig_act;

	ft_printf("%3s\n", "ferlgre");
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
