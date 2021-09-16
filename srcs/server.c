
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

static void	ft_action(int sig_num, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;
	static int	pid = 0;
	static char	*buff;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
//	if (kill(pid, SIGUSR1) == -1)
//		error("error while sending aknowledgment of receipt of bit\n");
	if (sig_num == SIGUSR2)
		c = c | (0x80 >> bits);
	else if (sig_num == SIGUSR1)
		c = c ^ (0x80 >> bits);
	bits++;
	if (bits == 8)
	{
		if (kill(pid, SIGUSR2) == -1)
			error("error while sending aknowledgment of receipt of char\n");
		if (!buff)
			buff = init_buff(c);
		else
			buff = strfjoinchar(buff, c);
		if (c == 0)
		{
			ft_printf("%s", buff);
//			ft_memset(buff, 0xFF, ft_strlen(buff));
			free(buff);
			buff = NULL;
		}
		c = 0xFF;
		bits = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction action;

	if (argc != 1)
		error("no arguments needed");
	(void)argv;
	action.sa_sigaction = ft_action;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
}
