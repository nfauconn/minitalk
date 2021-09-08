/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:53:24 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:46:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_percent(va_list *ap, t_conv *conv)
{
	(void)ap;
	if (IS_WIDTH && WIDTH > 1)
	{
		LEN = WIDTH;
		TO_CONV = ft_memalloc(LEN + 1);
		if (ZERO_PADDED && !LEFT)
			ft_memset(TO_CONV, '0', LEN);
		else
			ft_memset(TO_CONV, ' ', LEN);
		if (LEFT)
			TO_CONV[0] = '%';
		else
			TO_CONV[LEN - 1] = '%';
	}
	else
	{
		LEN = 1;
		TO_CONV = ft_memalloc(2);
		TO_CONV[0] = '%';
	}
}
