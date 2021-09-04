/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/04 16:26:18 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*signal_handler(int sig_num)
{
	ft_printf("sig_num = %d\n", sig_num);
	return ("lol");
}

int	main(int argc, char **argv)
{
	int 				sig_num;
	struct sigaction	s;

	(void)argc;
	ft_printf("%d\n", getpid());
	s.sa_handler = signal_handler(sig_num);
	sigaction(sig_num, &s, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
