/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:39:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/05 15:38:18 by ecorona-         ###   ########.fr       */
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

	(void)line;
	(void)temp;
	(void)nl;
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
	return (1);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("/home/eco/Desktop/42Cursus/get_next_line/test.txt",
			O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
}
