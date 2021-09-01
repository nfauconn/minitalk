/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:59:17 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 15:25:41 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"

void			convert(va_list *ap, t_pf *pf)
{
	t_conv	conv;

	init_conv(&conv);
	parse_flag(pf, &conv, ap);
	if (parse_conv(pf) != -1)
	{
		pf->fun_ptr[pf->index_conv](ap, &conv);
		insert_into_buffer(pf, conv.to_conv, conv.len);
		free(conv.to_conv);
		conv.to_conv = NULL;
	}
}
