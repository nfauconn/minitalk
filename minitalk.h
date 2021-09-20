/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:21:57 by user42            #+#    #+#             */
/*   Updated: 2021/09/20 12:20:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

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
void	error_server(char *s, char **str);
int		ft_atoi(const char *s);
char	*ft_itoa(int num);
int		ft_nbrlen_base(int nbr, int base);
void	ft_putstr_fd(char *s, int fd);
char	*strfjoinchar(char *str, char c);
int		str_isdigit(char *str);
size_t	ft_strlen(const char *str);

#endif
