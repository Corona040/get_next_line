/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:39:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/05 18:39:42 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	if (fd < 0)
		return (0);
	line = 0;
	read_line(fd, buffer, &line);
	return (line);
}

int	read_line(int fd, char buffer[], char **line)
{
	char	*temp;
	char	*nl;
	size_t	read_size;

	if (buffer)
		*line = ft_strdup(buffer);
	nl = 0;
	do
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		temp = *line;
		*line = ft_strjoin(*line, buffer);
		free(temp);
		nl = ft_strchr(*line, '\n');
	}
	while (!nl && read_size == BUFFER_SIZE);
	if (read_size == BUFFER_SIZE)
	{
		ft_strlcpy(buffer, nl + 1, BUFFER_SIZE);
		*nl = 0;
	}
	else
		ft_bzero(buffer, BUFFER_SIZE);
	return (1);
}
