/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: puttasa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:13:15 by puttasa           #+#    #+#             */
/*   Updated: 2022/12/22 16:16:01 by puttasa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;

	fd = open("fd_Basic_Input", O_RDONLY);
	line = get_next_line(fd);
	while (*line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
}
