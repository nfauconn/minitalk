/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:34:52 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/17 17:43:57 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../../includes/libft.h"

# define CONVFLAGS "cspdiuxX%-0.*123456789"
# define CONV "cspdiuxX%"
# define FLAGS "-0.*123456789"
# define BUFFSIZE 3

enum
{
	c = 0,
	s,
	p,
	d,
	i,
	u,
	x,
	mx,
	percent,
	end_enum,
};

typedef unsigned long long	t_ull;

typedef struct	s_conv
{
	size_t	left;
	size_t	zero_padded;
	size_t	is_width;
	size_t	width;
	size_t	is_prec;
	size_t	prec;
	size_t	if_positive;
	char	sign;
	size_t	hashtag;
	size_t	len;
	size_t	size;
	char	*to_conv;
	size_t	nb_spaces;
	size_t	nb_zeros;
}				t_conv;

typedef struct	s_pf
{
	char	*format;
	char	*buffer;
	size_t	bufsize;
	char	*ptr;
	int		index_conv;
	size_t	bufalloc;
	void	(*fun_ptr[end_enum])(va_list *, t_conv *);
}				t_pf;

int				ft_printf(const char *str, ...);
void			init_pf(t_pf *pf, const char *format);
void			init_conv(t_conv *conv);
void			insert_into_buffer(t_pf *pf, char *insert, size_t len);
void			convert(va_list *ap, t_pf *pf);
void			conv_c(va_list *ap, t_conv *conv);
void			conv_s(va_list *ap, t_conv *conv);
void			conv_p(va_list *ap, t_conv *conv);
void			conv_d_i(va_list *ap, t_conv *conv);
void			conv_u(va_list *ap, t_conv *conv);
void			conv_x(va_list *ap, t_conv *conv);
void			conv_mx(va_list *ap, t_conv *conv);
void			conv_percent(va_list *ap, t_conv *conv);
void			nb_spaces_zeros(t_conv *conv, size_t sign);
void			fill_without_pw(t_conv *conv, char *str, size_t sign);
void			fill_with_pw(t_conv *conv, const char *str, size_t sign);
int				main_loop(t_pf *pf, va_list *ap);
void			parse_flag(t_pf *pf, t_conv *conv, va_list *ap);
int				parse_conv(t_pf *pf);
void			convert(va_list *ap, t_pf *pf);

#endif
