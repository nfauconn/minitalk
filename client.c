#include "minitalk.h"

t_infos	infos = {NULL, 0, 0, 0, 0, 0};

pid_t	get_pid(char *nb)
{
	pid_t	pid;

	if (!str_isdigit(nb))
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = ft_atoi(nb);
	return (pid);
}

static void	send_bit(char letter, int comparator, pid_t pid)
{
	if (letter == 0 && comparator == 0)
	{
		while (++infos.bitshift < 8)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		return ;
	}
	if (letter & comparator)
	{
		infos.kill_exec = kill(pid, SIGUSR2);
		if (infos.kill_exec == -1)
			error("error while sending signal\nplease verify PID");
		usleep(100);
	}
	else
	{
		infos.kill_exec = kill(pid, SIGUSR1);
		if (infos.kill_exec == -1)
			error("error while sending signal\nplease verify PID");
		usleep(100);
	}
}

void	send_signal(pid_t pid)
{
	if (!infos.message[infos.i])
		send_bit(0, 0, pid);
	else
	{
		if (++infos.bitshift < 8)
		{
			infos.comparator = 0x80 >> infos.bitshift;
			send_bit(infos.message[infos.i], infos.comparator, pid);
		}
		if (infos.bitshift == 8)
		{
			infos.i++;
			infos.bitshift = -1;
			send_signal(infos.pid);
		}
	}
}

void	send_first_signal(char c, pid_t pid)
{
	infos.comparator = 0x80 >> infos.bitshift;
	send_bit(c, infos.comparator, pid);
	usleep(100);
}

static void	handler(int sig_num)
{
	static int	j = 0;

	if (sig_num == SIGUSR1)
	{
		j++;
		send_signal(infos.pid);
	}
	if (sig_num == SIGUSR2)
	{
		ft_putstr_fd("\nmessage sent successfully\n\n", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction action;

	if (argc != 3)
		error("wrong arguments\nformat : ./client <PID> <message>");
	infos.pid = get_pid(argv[1]);
	infos.message = argv[2];
	action.sa_handler = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_first_signal(infos.message[infos.i], infos.pid);
	while (1)
		pause();
	return (0);
}
