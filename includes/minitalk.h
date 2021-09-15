/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:10:50 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/15 19:56:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_infos
{
	char	*message;
	pid_t	pid;
	int		i;
	int		bitshift;
	int		comparator;
}	t_infos;

void	error(char *s);
void	error_server(int pid, char *str);

#endif
