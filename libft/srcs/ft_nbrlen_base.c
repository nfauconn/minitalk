/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:50:25 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 10:34:37 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_base(unsigned long long nbr, int base)
{
	int	ret;

	ret = 1;
	nbr /= base;
	while (nbr)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}
