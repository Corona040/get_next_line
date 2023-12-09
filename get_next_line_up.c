/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:21:12 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/27 11:29:46 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	read_buffer(char buffer[], char **line)
{
	int	len;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	return (len);
}

int	alloc_line(char **line, int len)
{
	int		i;
	char	*temp;

	temp = 0;
	if (*line)
		temp = *line;
	*line = malloc(len * sizeof(char));
	if (!*line)
	{
		free(temp);
		return (-1);
	}
	i = 0;
	while (temp && temp[i])
	{
		*line[i] = temp[i];
		i++;
	}
	free(temp);
	return (i);
}

void	write_line(char buffer[], char **line, int len)
{
	int	i;
	int	j;

	while (*line && *line[j])
		j++;
	i = 0;
	while (i < len)
	{
		*line[j + i] = buffer[i]; //BUG
		i++;
	}
	*line[i] = '\0'; //BUG
}

void	write_buffer(char buffer[], char **line, int len)
{
	int	i;

	i = 0;
	while (buffer[len - 1] && len <= BUFFER_SIZE)
		buffer[i++] = buffer[len++];
}

char	*read_line(char buffer[], char **line, int len, int fd)
{
	char	*temp;
	int		loop;
	int		read_size;
	int		buffer_len;
	int		line_len;

	loop = 1;
	while (loop)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
		{
			free(*line);
			return (0);
		}
		buffer_len += read_buffer(buffer, line);
		len += buffer_len;
		line_len = alloc_line(line, len);
		if (line_len < 0)
			return (0);
		write_line(buffer, line, buffer_len);
		len += line_len;
		*line[len] = '\0'; //BUG
		if (buffer_len > 0 && buffer[buffer_len - 1] == '\n')
		{
			write_buffer(buffer, line, buffer_len);
			loop = 0;
		}
		if (read_size < BUFFER_SIZE)
			loop = 0;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			len;

	len = 0;
	line = 0;
	if (fd < 0)
		return (0);
	len = read_buffer(buffer, &line);
	if (alloc_line(&line, len) < 0)
		return (0);
	write_line(buffer, &line, len);
	if (len > 0 && buffer[len - 1] == '\n')
		write_buffer(buffer, &line, len);
	else
		return (read_line(buffer, &line, len, fd));
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	nb_line = 10;
	int	nb_open = 1;

	while (nb_open)
	{
		fd = open("./banana.txt", O_RDONLY);
		while (nb_line)
		{
			printf("%s", get_next_line(fd));
			nb_line--;
		}
		close(fd);
		nb_open--;
	}
}
*/
