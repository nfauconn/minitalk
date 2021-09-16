#include "minitalk.h"

void	error(char *s)
{
	if (s)
		ft_printf("\n%s\n\n", s);
	exit(EXIT_FAILURE);
}

void	error_server(int pid, char *str)
{
	if (str)
		free(str);
	ft_printf("server: unexpected error.\n");
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}
