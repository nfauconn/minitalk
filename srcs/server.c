/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/04 17:06:37 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//https://github.com/mlanca-c/Minitalk/wiki/Projecct#1st-step-make-server-receive-a-signal-from-client

void	*signal_handler(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		sig_num = 0;
		ft_printf("sigsur1 exec = %d\n", sig_num);
	}
	if (sig_num == SIGUSR2)
	{
		sig_num = 1;
		ft_printf("sigusr2 exec = %d\n", sig_num);	
	}
	return ("sig");
}

int	main()
{
	struct sigaction	s;

	ft_printf("%d\n", getpid());
	s.sa_handler = signal_handler(SIGUSR1);
	s.sa_handler = signal_handler(SIGUSR2);
	while (1)
	{
		pause();
	}
	return (0);
}
