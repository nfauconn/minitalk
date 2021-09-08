/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:22:49 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:45:20 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	nb_to_array(t_conv *conv, char **str, int *i, size_t base)
{
	size_t	is_neg;

	is_neg = 0;
	if (*i < 0)
	{
		is_neg = 1;
		if (*i == -2147483648)
			*str = ft_strdup("2147483648");
		else
			*i = -(*i);
	}
	if (*i == 0 && IS_PREC && PREC == 0)
		*str = ft_strdup("");
	else if (*i != -2147483648)
		*str = ft_ulltoa_base(*i, base, 0);
	return (is_neg);
}

static void	fill_sign(t_conv *conv, size_t is_neg, size_t *sign)
{
	*sign = 1;
	if (is_neg)
		SIGN = '-';
	else if (IF_POSITIVE)
	{
		if (IF_POSITIVE > 2)
			SIGN = '+';
		else
			SIGN = ' ';
	}
}

void	conv_d_i(va_list *ap, t_conv *conv)
{
	int		i;
	char	*str;
	size_t	is_neg;
	size_t	sign;

	i = (long)va_arg(*ap, int);
	sign = 0;
	is_neg = nb_to_array(conv, &str, &i, 10);
	if (is_neg || IF_POSITIVE)
		fill_sign(conv, is_neg, &sign);
	LEN = ft_strlen(str);
	if ((PREC <= LEN) && (WIDTH <= (LEN + sign)))
	{
		fill_without_pw(conv, str, sign);
		free(str);
		return ;
	}
	spaces_zeros(conv, sign);
	TO_CONV = ft_memalloc(LEN + SPACES + sign + ZEROS + 1);
	fill_with_pw(conv, str, sign);
	free(str);
}
