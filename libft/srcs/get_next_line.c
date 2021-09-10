/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:24:05 by nfauconn          #+#    #+#             */
/*   Updated: 2021/09/10 12:59:23 by leo              ###   ########.fr       */
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
	*rest = line_return(*over);
	ret = read(fd, buff, BUFFER_SIZE);
	while (!*rest && ret > 0)
	{
		buff[ret] = '\0';
		fill_over(over, ft_strjoin(*over, buff));
		*rest = line_return(*over);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static char	*over[10240];
	size_t		ret;
	char		*rest[10240];
	size_t		len;

	rest[fd] = NULL;
	ret = ft_read(fd, &over[fd], &rest[fd]);
	if (fd > 10240 || fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_substr(over[fd], 0, rest[fd] - over[fd]);
	len = ft_strlen(over[fd]) - ft_strlen(*line);
	fill_over(&over[fd], ft_substr(over[fd], rest[fd] - over[fd] + 1, len));
	if ((ret == 0 && len > 0) || ret > 0)
		ret = 1;
	if (ret <= 0)
	{
		free(over[fd]);
		over[fd] = NULL;
	}
	return (ret);
}
