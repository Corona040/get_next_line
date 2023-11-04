/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:39:18 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/03 16:40:48 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int	ft_find_newl(const char *str)
{
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	t_line	line;

	read(fd, line.temp, BUFFER_SIZE);
	printf("%s\n", line.temp);
	while (!ft_find_newl((const char *) line->temp))
	{
		read(fd, line->temp, BUFFER_SIZE);
		line.next_line = ft_calloc(ft_strlen(line->temp), sizeof(char));
		if (!line.next_line)
			return (0);
		printf("%s\n", line->temp);
		break;
	}
	return (0);
}

int	main(void)
{
	int	fd;

	fd = open("/nfs/homes/ecorona-/Desktop/42Cursus/get_next_line/test.txt",
			O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}
