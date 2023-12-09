/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:41:24 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/27 11:09:01 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			read_size;

	int	i;
	int	j;
	int	k;

	if (fd < 0)
		return (0);
	i = 0;
	//read buffer
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	//write buffer to line
	line = malloc(i * sizeof(char));
	if (!line)
		return (0);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	//if   whole line was in buffer, write buffer
	//else read file
	j = 0;
	if (i > 0 && buffer[i - 1] == '\n')
	{
		while (buffer[i - 1] && i <= BUFFER_SIZE)
			buffer[j++] = buffer[i++];
	}
	else
	{
		char	*temp;
		int		loop;
		//write buffer
		loop = 1;
		while (loop)
		{
			read_size = read(fd, buffer, BUFFER_SIZE);
			if (read_size == 0)
			{
				free(line);
				return (0);
			}
			//read buffer
			j = 0;
			while (buffer[j] && buffer[j] != '\n')
				j++;
			if (buffer[j] == '\n')
				j++;
			//write buffer to line
			i += j;
			temp = line;
			line = malloc(i * sizeof(char));
			if (!line)
			{
				free(temp);
				return (0);
			}
			k = 0;
			while (temp[k])
			{
				line[k] = temp[k];
				k++;
			}
			free(temp);
			i = 0;
			while (i < j)
			{
				line[k + i] = buffer[i];
				i++;
			}
			i += k;
			line[i] = '\0';
			k = 0;
			if (j > 0 && buffer[j - 1] == '\n')
			{
				while (j <= BUFFER_SIZE)
					buffer[k++] = buffer[j++];
				if (!buffer[j - 1])
					buffer[k] = buffer[j - 1];
				loop = 0;
			}
			if (read_size < BUFFER_SIZE)
				loop = 0;
		}
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;
	int	j;

	j = 0;
	while (j < 1)
	{
		fd = open("./banana.txt", O_RDONLY);
		//fd = -1;
		i = 0;
		while (i < 13)
		{
			printf("%s", get_next_line(fd));
			i++;
		}
		close(fd);
		j++;
	}
}
*/
