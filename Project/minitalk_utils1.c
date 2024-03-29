/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:20:52 by nfauconn          #+#    #+#             */
/*   Updated: 2024/01/27 15:54:52 by nfauconn         ###   ########.fr       */
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
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

void	error(char *s)
{
	if (s)
	{
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
	}
	exit(EXIT_FAILURE);
}

void	error_server(char *s, char **str)
{
	if (s)
	{
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
	}
	if (*str)
		free(*str);
	exit(EXIT_FAILURE);
}
