/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:27:49 by puttasa           #+#    #+#             */
/*   Updated: 2022/11/29 22:19:00 by puttasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *tmp)
{
	char	*buff;
	int		checkread;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
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
		tmp = ft_strjoin(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*ft_get_line(char *tmp)
{
	char	*line;
	int		len;
	int		i;
	
	i = 0;
	len = ft_linelen(tmp);
	if (!tmp[0])
		return (0);
	line = malloc(sizeof(char) * (len + 2));
	if (!line)
		return (0);
	while (i < len)
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_extra_line(char *tmp)
{
	int		len;
	int		i;
	char	*line;

	i = 0;
	len = ft_linelen(tmp);
	if (!tmp[len])
	{
		free(tmp);
		return (0);
	}
	line = malloc(sizeof(char) * (ft_strlen(tmp) - len + 1));
	if (!line)
		return (0);
	len++;
	while (tmp[len])
		line[i++] = tmp[len++];
	line[i] = '\0';
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (!tmp)
	{
		tmp = malloc(1);
		tmp[0] = '\0';
	}
	tmp = ft_read(fd, tmp);
	if (!*tmp)
	{
		free(tmp);
		return (0);
	}
	line = ft_get_line(tmp);
	tmp = ft_extra_line(tmp);
	return (line);
}
