/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:55:51 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:46:21 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_width(t_conv *conv, size_t to_copy)
{
	LEN = WIDTH;
	TO_CONV = ft_memalloc(WIDTH + 1);
	if (!LEFT)
		SPACES = WIDTH - to_copy;
	if (ZERO_PADDED && !LEFT)
		ft_memset(TO_CONV, '0', LEN);
	else
		ft_memset(TO_CONV, ' ', LEN);
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
	LEN = ft_strlen(str);
	if (IS_PREC && PREC < LEN)
		LEN = PREC;
	to_copy = LEN;
	if (IS_WIDTH && WIDTH > LEN)
		fill_width(conv, to_copy);
	else
		TO_CONV = ft_memalloc(LEN + 1);
	ft_memcpy(TO_CONV + SPACES, str, to_copy);
	if (i == 1)
		free(str);
}
