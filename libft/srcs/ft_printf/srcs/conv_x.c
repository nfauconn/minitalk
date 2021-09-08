/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 22:58:14 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/08 11:45:20 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	nb_to_array(t_conv *conv, char **str, unsigned int *i)
{
	if (*i == 0 && IS_PREC && PREC == 0)
		*str = ft_strdup("");
	else
		*str = ft_ulltoa_base(*i, 16, 0);
}

void	conv_x(va_list *ap, t_conv *conv)
{
	unsigned int		i;
	char				*str;

	if (HASHTAG)
	{
		conv_p(ap, conv);
		return ;
	}
	i = (unsigned int)va_arg(*ap, void *);
	nb_to_array(conv, &str, &i);
	LEN = ft_strlen(str);
	if (i != 0 && (PREC <= LEN) && (WIDTH <= (LEN)))
	{
		fill_without_pw(conv, str, 0);
		free(str);
		return ;
	}
	spaces_zeros(conv, 0);
	TO_CONV = ft_memalloc(LEN + SPACES + ZEROS + 1);
	fill_with_pw(conv, str, 0);
	free(str);
}
