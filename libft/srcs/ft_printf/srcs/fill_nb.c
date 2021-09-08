/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:17:49 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:48:16 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spaces_zeros(t_conv *conv, size_t sign)
{
	if (PREC <= LEN && WIDTH > (LEN + sign))
	{
		SPACES = WIDTH - LEN - sign;
		if (ZERO_PADDED && !LEFT && !IS_PREC)
		{
			ZEROS = SPACES;
			SPACES = 0;
		}
	}
	else if (PREC > LEN)
	{
		if (WIDTH > (PREC + sign))
			SPACES = WIDTH - PREC - sign;
		ZEROS = PREC - LEN;
	}
}

void	fill_without_pw(t_conv *conv, char *str, size_t sign)
{
	LEN += sign;
	TO_CONV = ft_memalloc(LEN + 1);
	if (sign)
		ft_memset(TO_CONV, SIGN, 1);
	ft_memcpy(TO_CONV + sign, str, LEN);
}

void	fill_with_pw(t_conv *conv, const char *str, size_t sign)
{
	if (LEFT)
	{
		if (sign)
			ft_memset(TO_CONV, SIGN, 1);
		ft_memset(TO_CONV + sign, '0', ZEROS);
		ft_memcpy(TO_CONV + sign + ZEROS, str, LEN);
		ft_memset(TO_CONV + sign + ZEROS + LEN, ' ', SPACES);
	}
	else
	{
		ft_memset(TO_CONV, ' ', SPACES);
		if (sign)
			ft_memset(TO_CONV + SPACES, SIGN, 1);
		ft_memset(TO_CONV + SPACES + sign, '0', ZEROS);
		ft_memcpy(TO_CONV + SPACES + sign + ZEROS, str, LEN + sign);
	}
	LEN += SPACES + sign + ZEROS;
}
