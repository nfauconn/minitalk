/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:20:35 by user42            #+#    #+#             */
/*   Updated: 2021/09/18 16:20:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*negative_case(int num, char *str, int i, int count)
{
	int	neg;

	str[0] = '-';
	neg = -num;
	while (neg > 0)
	{
		str[i] = '0' + (neg % 10);
		neg = neg / 10;
		i--;
	}
	str[count] = '\0';
	return (str);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		count;
	int		i;

	count = ft_nbrlen_base(num, 10);
	str = (char *)malloc((count + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = count - 1;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
		return (negative_case(num, str, i, count));
	else
	{
		while (num > 0)
		{
			str[i] = '0' + (num % 10);
			num = num / 10;
			i--;
		}
	}
	str[count] = '\0';
	return (str);
}

int	ft_nbrlen_base(int nbr, int base)
{
	int	ret;

	ret = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		ret++;
	}
	nbr /= base;
	while (nbr)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

int	ft_atoi(const char *s)
{
	int					sign;
	unsigned long long	nbr;

	nbr = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nbr = (nbr * 10) + (*s - '0');
		s++;
	}
	if (nbr > 2147483647)
		if (nbr == 2147483648 && sign == -1)
			return (-2147483648);
	return ((int)(nbr * sign));
}

char	*strfjoinchar(char *str, char c)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new_str)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	new_str[++i] = '\0';
	free(str);
	return (new_str);
}
