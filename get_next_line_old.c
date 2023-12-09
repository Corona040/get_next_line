/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:41:24 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/23 11:34:39 by ecorona-         ###   ########.fr       */
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
	if (!buffer[i])
		i--;
	//i is newline idx in buffer or buffer len if no newline
	//write buffer to line
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (0);
	j = 0;
	while (j <= i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	//if   whole line was in buffer, write buffer
	//else read file
	j = 0;
	if (buffer[i] == '\n')
	{
		while (buffer[i] && i < BUFFER_SIZE)
			buffer[j++] = buffer[++i];
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
			//read buffer
			j = 0;
			while (buffer[j] && buffer[j] != '\n')
				j++;
			if (!buffer[j])
				j--;
			//write buffer to line
			i += j;
			temp = line;
			line = malloc((i+1) * sizeof(char));
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
			while (i <= j)
			{
				line[k + i] = buffer[i];
				i++;
			}
			i += k;
			line[i] = '\0';
			k = 0;
			if (buffer[j] == '\n')
			{
				while (buffer[j] && j < BUFFER_SIZE)
					buffer[k++] = buffer[++j];
				loop = 0;
			}
			if (read_size < BUFFER_SIZE)
			{
				/*
				k = 0;
				while (k < BUFFER_SIZE)
					buffer[k++] = '\0';
				*/
				return (line);
			}
		}
	}
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	i;

	fd = open("./banana.txt", O_RDONLY);
	i = 0;
	while (i < 20)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
}
