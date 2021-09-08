/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:55:51 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 12:20:15 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_width(t_conv *conv, size_t to_copy)
{
	conv->len = conv->width;
	conv->str = ft_memalloc(conv->width + 1);
	if (!conv->left)
		conv->nb_spaces = conv->width - to_copy;
	if (conv->zero_padded && !conv->left)
		ft_memset(conv->str, '0', conv->len);
	else
		ft_memset(conv->str, ' ', conv->len);
}

void	conv_s(va_list *ap, t_conv *conv)
{
	char	*str;
	size_t	i;
	size_t	to_copy;

	i = 0;
	str = (char *)va_arg(*ap, char *);
	if (!str)
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
		conv->str = ft_memalloc(conv->len + 1);
	ft_memcpy(conv->str + conv->nb_spaces, str, to_copy);
	if (i == 1)
		free(str);
}
