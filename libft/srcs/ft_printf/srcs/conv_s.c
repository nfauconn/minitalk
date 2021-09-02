/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:55:51 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 15:25:41 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_width(t_conv *conv, size_t to_copy)
{
	conv->len = conv->width;
	conv->to_conv = ft_memalloc(conv->width + 1);
	if (!conv->left)
		conv->nb_spaces = conv->width - to_copy;
	if (conv->zero_padded && !conv->left)
		ft_memset(conv->to_conv, '0', conv->len);
	else
		ft_memset(conv->to_conv, ' ', conv->len);
}

void		conv_s(va_list *ap, t_conv *conv)
{
	char	*str;
	size_t	i;
	size_t	to_copy;

	i = 0;
	if (!(str = (char*)va_arg(*ap, char *)))
	{
		str = ft_strdup("(null)");
		i = 1;
	}
	conv->len = ft_strlen(str);
	if (conv->is_prec && conv->prec < conv->len)
		conv->len = conv->prec;
	to_copy = conv->len;
	if (conv->is_width && conv->width > conv->len)
		fill_width(conv, to_copy);
	else
		conv->to_conv = ft_memalloc(conv->len + 1);
	ft_memcpy(conv->to_conv + conv->nb_spaces, str, to_copy);
	if (i == 1)
		free(str);
}
