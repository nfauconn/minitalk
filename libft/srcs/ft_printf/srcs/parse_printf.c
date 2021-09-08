/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:37:36 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:48:58 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_flags(t_pf *pf, t_conv *conv)
{
	char c;

	c = *PTR;
	while (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
	{
		if (c == '-')
			LEFT = 1;
		if (c == '0')
			ZERO_PADDED = 1;
		if (c == '+')
			IF_POSITIVE = 3;
		if (c == ' ' && IF_POSITIVE != 3)
			IF_POSITIVE = 2;
		if (c == '#')
			HASHTAG = 1;
		PTR++;
		c = *PTR;
	}
}

static void	set_width(t_pf *pf, t_conv *conv, va_list *ap)
{
	int		w;

	IS_WIDTH = 1;
	if (*PTR == '*')
	{
		w = (int)va_arg(*ap, int);
		if (!w)
			WIDTH = 0;
		if (w < 0)
		{
			LEFT = 1;
			WIDTH = -w;
		}
		else
			WIDTH = w;
		PTR++;
	}
	else
		while (*PTR && ft_isdigit(*PTR))
			WIDTH = (WIDTH * 10) + (*PTR++ - '0');
}

static void	set_prec(t_pf *pf, t_conv *conv, va_list *ap)
{
	int		p;

	IS_PREC = 1;
	PTR++;
	if (*PTR == '*')
	{
		p = (int)va_arg(*ap, int);
		if (!p)
			PREC = 0;
		if (p < 0)
			IS_PREC = 0;
		else
			PREC = p;
		PTR++;
	}
	else
		while (*PTR && ft_isdigit(*PTR))
			PREC = (PREC * 10) + (*PTR++ - '0');
}

void	parse_flag(t_pf *pf, t_conv *conv, va_list *ap)
{
	while (*PTR && (ft_isflagpf(*PTR) || ft_isdigit(*PTR)))
	{
		if (*PTR == '-' || *PTR == '0' || *PTR == '+')
			set_flags(pf, conv);
		if (*PTR == ' ' || *PTR == '#')
			set_flags(pf, conv);
		if (ft_isdigit(*PTR) || *PTR == '*')
			set_width(pf, conv, ap);
		if (*PTR == '-' || *PTR == '+' || *PTR == ' ' || *PTR == '#')
			set_flags(pf, conv);
		if (*PTR == '.')
			set_prec(pf, conv, ap);
	}
}

int	parse_conv(t_pf *pf)
{
	int	i;

	i = 0;
	while (*PTR && CONV[i])
	{
		if (CONV[i] == *PTR)
		{
			pf->index_conv = i;
			PTR++;
			return (i);
		}
		i++;
	}
	return (-1);
}
