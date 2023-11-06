/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:39:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/06 15:40:12 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//REMEMBER TO REMOVE PRINTF
//#include <stdio.h>

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
	if (!ft_strchr(buffer, '\n'))
	{
		do
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			temp = *line;
			*line = ft_strjoinnul(*line, buffer);
			//printf("%s", *line);
			if (temp)
				free(temp);
			nl = ft_strchr(*line, '\n');
		}
		while (!nl && read_size == BUFFER_SIZE);
		if (read_size == BUFFER_SIZE)
		{
			ft_strlcpy(buffer, nl + 1, BUFFER_SIZE);
			//THIS LEAVES TRASH AFTER NULL BYTE, SHOULD REALLOC LINE TO PROPER SIZE
			*(nl + 1) = 0;
		}
		else
		{
			ft_bzero(buffer, BUFFER_SIZE);
			*line = 0;
		}
	}
	else
	{
		*(ft_strchr(*line, '\n') + 1) = 0;
		ft_strlcpy(buffer, buffer + 1, BUFFER_SIZE);
	}
	return (1);
}

/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("/home/eco/Desktop/42cursus/get_next_line/tests/banana.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}
*/
