/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:51:09 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:00:56 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strfdup(char **over, char *buff)
{
	char	*tmp;

	if (!over)
		return ;
	tmp = *over;
	*over = ft_strdup(buff);
	free(tmp);
}
