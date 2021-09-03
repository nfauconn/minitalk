/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfauconn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:24:05 by nfauconn          #+#    #+#             */
/*   Updated: 2021/08/18 12:24:34 by nfauconn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*line_return(char *over)
{
	while (*over)
	{
		if (*over == '\n')
			return (over);
		over++;
	}
	return (NULL);
}

static int	fill_over(char **over, char *joined)
{
	char	*tmp;

	tmp = *over;
	*over = ft_strdup(joined);
	free(tmp);
	free(joined);
	return (1);
}

static int	ft_read(int fd, char **over, char **rest)
{
	int		ret;
	char	*buff;

	buff = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buff || read(fd, buff, 0) < 0)
		return (-1);
	if (!*over)
		*over = ft_strdup("");
	while (!(*rest = line_return(*over))
			&& (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		fill_over(over, ft_strjoin(*over, buff));
	}
	free(buff);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static char	*over[OPEN_MAX];
	size_t		ret;
	char		*rest[fd];
	size_t		len;

	rest[fd] = NULL;
	if (fd > OPEN_MAX || fd < 0 || !line || BUFFER_SIZE < 1
			|| (ret = (ft_read(fd, &over[fd], &rest[fd])) < 0))
		return (-1);
	*line = ft_substr(over[fd], 0, rest[fd] - over[fd]);
	len = ft_strlen(over[fd]) - ft_strlen(*line);
	fill_over(&over[fd], ft_substr(over[fd], rest[fd] - over[fd] + 1, len));
	ret = ((ret == 0 && len > 0) || ret > 0) ? 1 : ret;
	if (ret <= 0)
	{
		free(over[fd]);
		over[fd] = NULL;
	}
	return (ret);
}
