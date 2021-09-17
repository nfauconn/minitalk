/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:10:50 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/17 16:51:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_infos
{
	char	*message;
	pid_t	pid;
	int		i;
	int		bitshift;
	int		comparator;
	int		kill_exec;
}	t_infos;

void	error(char *s);
void	error_server(int pid, char *str);
int		ft_atoi(const char *s);
char	*ft_itoa(int num);
int		ft_nbrlen_base(int nbr, int base);
void	ft_putstr_fd(char *s, int fd);
char	*strfjoinchar(char *str, char c);
int		str_isdigit(char *str);
size_t	ft_strlen(const char *str);

#endif
