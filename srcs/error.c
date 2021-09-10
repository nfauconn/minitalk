/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:11:39 by leo               #+#    #+#             */
/*   Updated: 2021/09/10 14:04:51 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
