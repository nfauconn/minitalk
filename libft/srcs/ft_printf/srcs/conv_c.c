/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:20:43 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 15:38:50 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

static void		set_width(t_conv *conv, char c)
{
	conv->len = conv->width;
	conv->to_conv = ft_memalloc(conv->len + 1);
	ft_memset(conv->to_conv, ' ', conv->len);
	if (conv->left)
		conv->to_conv[0] = c;
	else
	{
		if (conv->zero_padded)
			ft_memset(conv->to_conv, '0', conv->len);
		conv->to_conv[conv->len - 1] = c;
	}
}

void			conv_c(va_list *ap, t_conv *conv)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*ap, int);
	if (conv->is_width && conv->width > 1)
		set_width(conv, c);
	else
	{
		conv->len = 1;
		conv->to_conv = ft_memalloc(2);
		conv->to_conv[conv->len - 1] = c;
	}
}
