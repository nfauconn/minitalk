/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:29:15 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/17 16:55:21 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	str_isdigit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str >= 9))
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	error(char *s)
{
	if (s)
	{
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
	}
	exit(EXIT_FAILURE);
}

/*void	error_server(int pid, char *str)
{
	if (str)
		free(str);
	ft_putstr_fd("server: unexpected error.\n", 2);
	exit(EXIT_FAILURE);
}*/
