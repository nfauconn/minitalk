/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 23:15:32 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:46:50 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_fun_ptr(t_pf *pf)
{
	pf->fun_ptr[c] = &conv_c;
	pf->fun_ptr[s] = &conv_s;
	pf->fun_ptr[p] = &conv_p;
	pf->fun_ptr[d] = &conv_d_i;
	pf->fun_ptr[i] = &conv_d_i;
	pf->fun_ptr[u] = &conv_u;
	pf->fun_ptr[x] = &conv_x;
	pf->fun_ptr[mx] = &conv_mx;
	pf->fun_ptr[percent] = &conv_percent;
}

void	init_conv(t_conv *conv)
{
	LEFT = 0;
	ZERO_PADDED = 0;
	IS_WIDTH = 0;
	WIDTH = 0;
	IS_PREC = 0;
	PREC = 0;
	IF_POSITIVE = 0;
	SIGN = 0;
	HASHTAG = 0;
	LEN = 0;
	TO_CONV = NULL;
	SPACES = 0;
	ZEROS = 0;
}

void	init_pf(t_pf *pf, const char *format)
{
	pf->format = (char *)format;
	pf->buffer = NULL;
	pf->bufsize = 0;
	pf->ptr = (char *)format;
	pf->index_conv = -1;
	pf->bufalloc = 0;
	init_fun_ptr(pf);
}
