/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:39:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/05 14:16:33 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	temp[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	char		*line;

	line = read_line(fd, buffer, temp);
	return (line);
}

char	*read_line(int fd, char buffer[], char temp[])
{
	char	*line;
	char	*nl;
	size_t	read_size;

	line = ft_calloc(1, sizeof(char));
	if (temp)
		line = ft_strdup(temp);
	nl = 0;
	do
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		nl = ft_strchr(line, '\n');
	}
	while (!nl && read_size);
	if (read_size == BUFFER_SIZE)
	{
		ft_strlcpy(temp, nl + 1, BUFFER_SIZE);
		*nl = 0;
	}
	return (line);
}


int	main(void)
{
	int	fd;

	fd = open("/home/eco/Desktop/42Cursus/get_next_line/test2.txt",
			O_RDONLY);
	//get_next_line(fd);
	//get_next_line(fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
