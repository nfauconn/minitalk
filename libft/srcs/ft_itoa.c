/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:01:03 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 12:22:05 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count(int num)
{
	int	count;
	int	neg;

	count = 0;
	if (num <= 0)
	{
		neg = -num;
		count++;
	}
	if (!count)
		while (num > 0)
		{
			num /= 10;
			count++;
		}
	else
		while (neg > 0)
		{
			neg /= 10;
			count++;
		}
	return (count);
}

static char	*negative_case(int num, char *str, int i, int count)
{
	int neg;

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

	count = ft_count(num);
	str = (char *)malloc((count + 1) * sizeof (char));
	if (!str)
		return (NULL);
	i = count - 1;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		return (negative_case(num, str, i, count));
	}
	else
		while (num > 0)
		{
			str[i] = '0' + (num % 10);
			num = num / 10;
			i--;
		}
	str[count] = '\0';
	return (str);
}
