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
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = ft_atoi(nb);
	if (pid <= 0 || pid > 32768)
		error("wrong PID");
	return (pid);
}

void	send_signals(char *message, pid_t pid)
{
	int		i;
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
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(3);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = get_pid(argv[1]);
	send_signals(argv[2], pid);
	return (0);
}
