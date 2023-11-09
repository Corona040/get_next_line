/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:29:30 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/09 11:47:57 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//REMEMBER TO UPDATE TESTER PATH WHEN WORKING ON A DIFFERENT MACHINE
// ^ updated this to a relative path, did not test, dont know if it still compiles

#include "get_next_line.h"
//remember to remove printf, stdio.h
#include <stdio.h>

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char        *line;

	line = 0;
	if (fd < 0)
		return (0);
	if (read_buffer(buffer, &line) == 1)
		read_line(fd, &line);
	return (line);
}

int	read_buffer(char buffer[], char **line)
{
	int	nl_ptr;

	nl_ptr = ft_strchr(buffer, '\n');
	if (nl_ptr);
	{
		//join to line from buffer until address nl_ptr (inclusive)
		*line = ft_strpjoinnul(line, buffer, nl_ptr);
		if (!*line)
			return (-1) //if malloc fails
		//similar to memmove, cpy to address buffer contents of nl_ptr until addres (buffer + BUFFERSIZE), and then bzero
		buffer = ft_buffermove(buffer, nl_ptr);
		return (0)
	}
	return (1);
}

void read_line(int fd, char *line)
{
	char	*temp;
	int		read_size;

	read_size = read(fd, temp, BUFFER_SIZE);
	*line = ft_strjoinnul(*line, temp); //free join
}

int	main(void)
{
	get_next_line(0);
}
