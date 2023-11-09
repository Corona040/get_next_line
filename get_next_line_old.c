/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:39:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/09 10:31:13 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//REMEMBER TO REMOVE PRINTF
#include <stdio.h>

/*

get_next_line(int fd)

vars
	static buffer
	read buffer (temp)
	return line
	read result

//empty file (temp = 0, return 0, buffer 0)
//file < buffer (temp = file, return += temp, buffer 0)
//file = buffer (temp = file, return += temp, buffer 0)
//file > buffer	(temp = file[:buffersize], return += temp, buffer = file[buffersize:]

*/

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = 0;
	read_line(fd, buffer, &line);
	return (line);
}

int	read_line(int fd, char buffer[], char **line)
{
	char	*temp_line;
	char	*temp_buffer;
	char	*nl;
	size_t	read_size;

	temp_buffer = ft_strdup(buffer); //NOT CHECKING IF DUP MALLOC FAILS
	if (buffer)
		*line = ft_strdup(buffer);
	nl = 0;
	if (!ft_strchr(buffer, '\n'))
	{
		do
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			temp_line = *line;
			*line = ft_strjoinnul(*line, buffer);
			if (temp_line)
				free(temp_line);
			nl = ft_strchr(*line, '\n');
			printf("%s", *line);
		}
		while (!nl && read_size == BUFFER_SIZE);
		if (read_size == BUFFER_SIZE)
		{
			ft_strlcpy(buffer, nl + 1, BUFFER_SIZE);
			*(nl + 1) = 0; //THIS LEAVES TRASH AFTER NULL BYTE, SHOULD REALLOC LINE TO PROPER SIZE
		}
		else if (*temp_buffer)
		{
			*line = 0;
			ft_bzero(buffer, BUFFER_SIZE);
		}
	}
	else
	{
		*(ft_strchr(*line, '\n') + 1) = 0;
		ft_strlcpy(buffer, buffer + 1, BUFFER_SIZE);
	}
	free(temp_buffer);
	return (1);
}

/*
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("/nfs/homes/ecorona-/Desktop/42Cursus/get_next_line/tests/banana.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}
*/
