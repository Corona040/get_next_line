/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:29:30 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/09 17:12:37 by ecorona-         ###   ########.fr       */
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

	if (fd < 0)
		return (0);
	if (read_buffer(&buffer, &line))
	{
		read_file(fd, &line);
	}
	return (line);
}

int	read_buffer(char *buffer[], char **line)
{
	//	empty
	//	not empty, no  nl
	//	not empty, has nl
	parse(&buffer, );
}

int	read_file(int fd, char **line)
{
	//loop
	//	no nl is read
	//	read_size < BUFFER_SIZE
	//if nl is read -> parse
	//if read_size < BUFFER_SIZE
	//	if read_size == 0 -> return line (line could be NULL)
	parse(&buffer, &line);
}

int	parse(char *src, char *dest1, char *dest2);

#include <fcntl.h>

int	main(void)
{
	int fd;

	fd = open("./tests/banana.txt", O_RDONLY);
	get_next_line(0);
}
