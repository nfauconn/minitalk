/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:21:34 by user42            #+#    #+#             */
/*   Updated: 2021/09/19 00:24:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*t_infos g_infos = {NULL, 0, 0, 0, 0, 0};

pid_t   get_pid(char *nb)
{
    pid_t   pid;

    if (!str_isdigit(nb))
        error("wrong arguments\nformat : ./client <PID> <message>");
    pid = ft_atoi(nb);
    return (pid);
}

static void send_bit(char letter, int comparator, pid_t pid)
{
    if (letter == 0 && comparator == 0)
    {
        while (++g_infos.bitshift < 8)
        {
            kill(pid, SIGUSR1);
            usleep(50);
        }
        return ;
    }
    if (letter & comparator)
    {
        g_infos.kill_exec = kill(pid, SIGUSR2);
        if (g_infos.kill_exec == -1)
            error("error while sending signal\nplease verify PID");
        usleep(50);
    }
    else
    {
        g_infos.kill_exec = kill(pid, SIGUSR1);
        if (g_infos.kill_exec == -1)
            error("error while sending signal\nplease verify PID");
        usleep(50);
    }
}

void    send_signal(pid_t pid)
{
    if (!g_infos.message[g_infos.i])
        send_bit(0, 0, pid);
    else
    {
        if (++g_infos.bitshift < 8)
        {
            g_infos.comparator = 0x80 >> g_infos.bitshift;
            send_bit(g_infos.message[g_infos.i], g_infos.comparator, pid);
        }
        if (g_infos.bitshift == 8)
        {
            g_infos.i++;
            g_infos.bitshift = -1;
            send_signal(g_infos.pid);
        }
    }
}

static void handler(int sig_num)
{
    static int  j = 0;

    if (sig_num == SIGUSR1)
    {
        j++;
        send_signal(g_infos.pid);
    }
    if (sig_num == SIGUSR2)
    {
        ft_putstr_fd("\nmessage sent successfully\n\n", 1);
        exit(1);
    }
}

int main(int argc, char **argv)
{
    struct sigaction    action;

    if (argc != 3)
        error("wrong arguments\nformat : ./client <PID> <message>");
    g_infos.pid = get_pid(argv[1]);
    g_infos.message = argv[2];
    action.sa_handler = handler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    g_infos.comparator = 0x80 >> g_infos.bitshift;
    send_bit(g_infos.message[g_infos.i], g_infos.comparator, g_infos.pid);
    usleep(50);
    while (1)
        pause();
    return (0);
}
*/

// ATTENTION AU INLUDE STDIO
#include <stdio.h>
// ATTENTION AU INLUDE STDIO

t_infos	g_infos = {NULL, 0, 0, -1, 0, 0};

pid_t	get_pid(char *nb)
{
	pid_t	pid;

	if (!str_isdigit(nb))
		error("wrong arguments\nformat : ./client <PID> <message>");
	pid = ft_atoi(nb);
	return (pid);
}

static void	send_bit(int sig, pid_t pid)
{
//	kill(pid, sig);
	g_infos.kill_exec = kill(pid, sig);
	if (g_infos.kill_exec == -1)
			error("error while sending signal\nplease verify PID");
	usleep(100);
}

void	send_signal(pid_t pid)
{
	if (!g_infos.message[g_infos.i])
	{
		while (++g_infos.bitshift < 8)
			send_bit(SIGUSR1, g_infos.pid);
	}
	else
	{
		while (++g_infos.bitshift < 8)
		{
			g_infos.comparator = 0x80 >> g_infos.bitshift;
			if (g_infos.message[g_infos.i] & g_infos.comparator)
				send_bit(SIGUSR2, g_infos.pid);
			else
				send_bit(SIGUSR1, g_infos.pid);
		}
		g_infos.i++;
		g_infos.bitshift = -1;
	}
}

static void	handler(int sig_num)
{
	if (sig_num == SIGUSR1)
	{
		printf("\nchar %d received\n\n", g_infos.i);
		send_signal(g_infos.pid);
	}
	else if (sig_num == SIGUSR2)
	{
		ft_putstr_fd("\n\nmessage sent successfully\n", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3)
		error("wrong arguments\nformat : ./client <PID> <message>");
	g_infos.pid = get_pid(argv[1]);
	g_infos.message = argv[2];
	action.sa_handler = handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_signal(g_infos.pid);
//	send_bit(g_infos.message[g_infos.i], g_infos.comparator, g_infos.pid);
	while (1)
		pause();
	return (0);
}
