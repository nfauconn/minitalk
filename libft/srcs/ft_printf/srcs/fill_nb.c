/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:17:49 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 12:20:15 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaces_zeros(t_conv *conv, size_t sign)
{
	if (conv->prec <= conv->len && conv->width > (conv->len + sign))
	{
		conv->nb_spaces = conv->width - conv->len - sign;
		if (conv->zero_padded && !conv->left && !conv->is_prec)
		{
			conv->nb_zeros = conv->nb_spaces;
			conv->nb_spaces = 0;
		}
	}
	else if (conv->prec > conv->len)
	{
		if (conv->width > (conv->prec + sign))
			conv->nb_spaces = conv->width - conv->prec - sign;
		conv->nb_zeros = conv->prec - conv->len;
	}
}

void	fill_without_pw(t_conv *conv, char *str, size_t sign)
{
	conv->len += sign;
	conv->str = ft_memalloc(conv->len + 1);
	if (sign)
		ft_memset(conv->str, conv->sign, 1);
	ft_memcpy(conv->str + sign, str, conv->len);
}

void	fill_with_pw(t_conv *conv, const char *str, size_t sign)
{
	if (conv->left)
	{
		if (sign)
			ft_memset(conv->str, conv->sign, 1);
		ft_memset(conv->str + sign, '0', conv->nb_zeros);
		ft_memcpy(conv->str + sign + conv->nb_zeros, str, conv->len);
		ft_memset(conv->str + sign + conv->nb_zeros + conv->len, ' ', conv->nb_spaces);
	}
	else
	{
		ft_memset(conv->str, ' ', conv->nb_spaces);
		if (sign)
			ft_memset(conv->str + conv->nb_spaces, conv->sign, 1);
		ft_memset(conv->str + conv->nb_spaces + sign, '0', conv->nb_zeros);
		ft_memcpy(conv->str + conv->nb_spaces + sign + conv->nb_zeros, str, conv->len + sign);
	}
	conv->len += conv->nb_spaces + sign + conv->nb_zeros;
}
