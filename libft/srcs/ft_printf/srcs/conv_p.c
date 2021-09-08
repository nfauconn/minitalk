/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:50:29 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:46:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_width(t_conv *conv, size_t *to_copy)
{
	if (IS_WIDTH && WIDTH > LEN)
	{
		LEN = WIDTH;
		TO_CONV = ft_memalloc(LEN + 1);
		if (!LEFT)
			SPACES = WIDTH - *to_copy;
		if (ZERO_PADDED && !LEFT)
			ft_memset(TO_CONV, '0', LEN);
		else
			ft_memset(TO_CONV, ' ', LEN);
	}
	else
		TO_CONV = ft_memalloc(*to_copy + 1);
}

void	conv_p(va_list *ap, t_conv *conv)
{
	char				*str;
	char				*tmp;
	void				*i;
	size_t				to_copy;

	tmp = NULL;
	i = (void *)va_arg(*ap, void *);
	str = ft_strdup("0x");
	tmp = ft_ulltoa_base((t_ull)i, 16, 0);
	ft_strfjoin(&str, tmp);
	free(tmp);
	LEN = ft_strlen(str);
	to_copy = LEN;
	fill_width(conv, &to_copy);
	ft_memcpy(TO_CONV + SPACES, str, to_copy);
	free(str);
}
