/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:58:22 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 12:22:05 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static int		str_nb(char const *s, char c)
{
	int		i;
	int		str_nb;

	i = 0;
	while (s[i] && (s[i] == c))
		i++;
	str_nb = 0;
	while (s[i])
	{
		while (s[i] && (s[i] != c))
			i++;
		str_nb++;
		while (s[i] && (s[i] == c))
			i++;
	}
	return (str_nb);
}

static int		str_len(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		index;
	int		i;
	int		j;

	index = 0;
	i = 0;
	if ((!s) || !(tab = malloc(sizeof(s) * (str_nb(s, c) + 1))))
		return (NULL);
	while (s[i] && (index < str_nb(s, c)))
	{
		while (s[i] == c)
			i++;
		if (!(tab[index] = malloc(sizeof(char) * (str_len(s + i, c) + 1))))
			return (NULL);
		j = 0;
		while (s[i] && s[i] != c)
			tab[index][j++] = s[i++];
		tab[index][j] = '\0';
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
