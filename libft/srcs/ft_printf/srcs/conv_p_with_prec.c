/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p_with_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:50:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 15:25:41 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

/*
static void		fill_prec(t_conv *conv, char **str, t_ull *i)
{
	char	*tmp;

	if (conv->prec == 0)
		*str = ft_strdup("0x");
	else
	{
		tmp = ft_ulltoa_base(*i, 16, 0);
		if (conv->prec > ft_strlen(tmp))
		{
			conv->len = 2 + conv->prec - ft_strlen(tmp);
			*str = ft_memalloc(conv->len);
			ft_memset(*str, '0', conv->len);
			ft_memcpy(*str, "0x", 2);
			ft_strfjoin(str, tmp);
		}
		else
		{
			*str = ft_strdup("0x");
			tmp = ft_ulltoa_base(*i, 16, 0);
			ft_strfjoin(str, tmp);
		}
	}
}*/

static void		fill_width(t_conv *conv, size_t *to_copy)
{
	if (conv->is_width && conv->width > conv->len)
	{
		conv->len = conv->width;
		conv->to_conv = ft_memalloc(conv->len + 1);
		if (!conv->left)
			conv->nb_spaces = conv->width - *to_copy;
		if (conv->zero_padded && !conv->left)
			ft_memset(conv->to_conv, '0', conv->len);
		else
			ft_memset(conv->to_conv, ' ', conv->len);
	}
	else
		conv->to_conv = ft_memalloc(*to_copy + 1);
}

void			conv_p(va_list *ap, t_conv *conv)
{
	char				*str;
	char				*tmp;
	t_ull				i;
	size_t				to_copy;

	tmp = NULL;
	if (!(i = (t_ull)va_arg(*ap, void*)))
	{
//		str = ft_strdup("0x");
		i = 0;
	}
//	if (conv->is_prec && (conv->prec > conv->width || conv->prec == 0))
//		fill_prec(conv, &str, &i);
//	else
//	{
		str = ft_strdup("0x");
		tmp = ft_ulltoa_base(i, 16, 0);
		ft_strfjoin(&str, tmp);
		free(tmp);
//	}
	conv->len = ft_strlen(str);
	to_copy = conv->len;
	fill_width(conv, &to_copy);
	ft_memcpy(conv->to_conv + conv->nb_spaces, str, to_copy);
	free(str);
}
