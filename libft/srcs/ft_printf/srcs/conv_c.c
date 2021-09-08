/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:20:43 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:46:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_width(t_conv *conv, char c)
{
	LEN = WIDTH;
	TO_CONV = ft_memalloc(LEN + 1);
	ft_memset(TO_CONV, ' ', LEN);
	if (LEFT)
		TO_CONV[0] = c;
	else
	{
		if (ZERO_PADDED)
			ft_memset(TO_CONV, '0', LEN);
		TO_CONV[LEN - 1] = c;
	}
}

void	conv_c(va_list *ap, t_conv *conv)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*ap, int);
	if (IS_WIDTH && WIDTH > 1)
		set_width(conv, c);
	else
	{
		LEN = 1;
		TO_CONV = ft_memalloc(2);
		TO_CONV[LEN - 1] = c;
	}
}
