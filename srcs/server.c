/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:09:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 19:05:07 by nfauconn         ###   ########.fr       */
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

static void	signal_handler(int sig_num)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static char	*buff;

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
}
