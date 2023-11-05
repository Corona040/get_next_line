/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <ecorona-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:53:41 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/05 18:32:17 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define PATH "/home/eco/Desktop/42Cursus/get_next_line/tests/"

void	test(char **tests, int repeat);

int main(void)
{
	int		repeat = 2;
	char	*tests[] =
	{
		"banana.txt",
		"LoremIpsum.txt",
		"empty.txt",
		"just_newlines.txt",
		0
	};

	test(tests, repeat);
}

void	test(char **tests, int repeat)
{
	int		i;
	int		fd;
	char	*line;
	char	*test;

	i = repeat;
	while (*tests)
	{
		if (i == repeat)
			printf("TEST: %s\n", *tests);
		printf("iteration: %i\n\n.", repeat - i + 1);
		test = ft_strjoin(PATH, *tests);
		fd = open(test, O_RDONLY);
		do
		{
			line = get_next_line(fd);
			printf("%s\n", line);
		} while (ft_strchr(line, '\n'));
		close(fd);
		printf(".\n\n");
		i--;
		if (i == 0)
		{
			i = repeat;
			tests++;
		}
		free(test);
	}
}
