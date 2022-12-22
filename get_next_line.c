/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:43:56 by puttasa           #+#    #+#             */
/*   Updated: 2022/12/22 16:03:34 by puttasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *box)
{
	char	*buff;
	int		checkread;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	checkread = 1;
	while (checkread && !ft_strchr(buff, '\n'))
	{
		checkread = read(fd, buff, BUFFER_SIZE);
		if (checkread == -1)
		{
			free(buff);
			return (0);
		}
		buff[checkread] = '\0';
		box = ft_strjoin(box, buff);
	}
	free(buff);
	return (box);
}

char	*ft_get_line(char *box)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_linelen(box);
	if (!box[0])
		return (0);
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (0);
	while (i < len)
	{
		line[i] = box[i];
		i++;
	}
	if (box[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_extra_line(char *box)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_linelen(box);
	if (!box[len])
	{
		free(box);
		return (0);
	}
	line = malloc(sizeof(char) * (ft_strlen(box) - len + 1));
	if (!line)
		return (0);
	len++;
	while (box[len])
		line[i++] = box[len++];
	line[i] = '\0';
	free(box);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*box;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (!box)
	{
		box = malloc(1);
		box[0] = '\0';
	}
	box = ft_read(fd, box);
	if (!box)
	{
		free(box);
		return (0);
	}
	line = ft_get_line(box);
	box = ft_extra_line(box);
	return (line);
}
