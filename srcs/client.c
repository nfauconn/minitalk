/* ************************************************************************** */
/* */
/*  :::::::::::*/
/*client.c :+::+: :+:*/
/* +:+ +:++:+  */
/*By: nfauconn <marvin@42.fr>  +#+  +:+ +#+  */
/*+#+#+#+#+#++#+  */
/*Created: 2021/09/01 17:09:26 by nfauconn #+# #+# */
/*Updated: 2021/09/04 15:52:38 by nfauconn###########.fr */
/* */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	get_pid(char *nb)
{
	pid_t	pid;

	if (!str_isdigit(nb))
		error("wrong arguments\nformat : ./client <PID> <message>\n");
	pid = ft_atoi(nb);
	if (pid <= 0 || pid > 32768)
		error("wrong PID\n");
	return (pid);
}

void	send_signals(char *message)
{
	int		bitshift;
	int		comparator;

	bitshift = -1;
	comparator = 0x80;
	ft_printf("%c[%d]: ", message[0], message[0]);
	while (++bitshift < 8)
	{
		comparator = comparator >> bitshift;
		if (message[0] & comparator)
			ft_printf("1");
		else
			ft_printf("0");
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error("wrong arguments\nformat : ./client <PID> <message>\n");
	pid = get_pid(argv[1]);
	send_signals(argv[2]);
	return (0);
}
