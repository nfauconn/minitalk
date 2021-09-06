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

/*
**By using the number 128 we get a binary number that has one 1 at the leftmost bit and then only 0 (10000000). 
**We then compare - by using the & operator - 128 with the number associated to the character we want client to send to server.
**
**This operator will return a 0 if the first bit of that character is zero, and it will return 128 if the first bit is one.
**
**Then the program will no longer use 128. Instead it will use the number 64 (128 >> 1 = 64). The number 64 is mostly 0, 
**save the second leftmost bit that is 1 (01000000). This will enable the program to get the character's second leftmost bit value.
*/

void	send_signal(pid_t pid, char *to_display)
{
	int	i;
	int	shift;

	if (!to_display)
		error();
	ft_printf("to_display in server prgm :%s\n", to_display);
	shift = -1;
	i = 0;
	while (to_display[i])
	{
		ft_printf("%c[%d]\n", to_display[i], to_display[i]);
		while (++shift < 8)
		{
			if (to_display[i] & 0x80 >> shift)
			{
				printf("1\n");
				kill(pid, SIGUSR2);
			}
			else
			{
				printf("0\n");
				kill(pid, SIGUSR1);
			}
			usleep(3);
		}
		ft_printf("\n");
		i++;
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
