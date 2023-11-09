/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:41:53 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/09 16:53:20 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//REMEMBER TO REMOVE LIBFT
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		read_buffer(char buffer[], char **line);
int		read_line(int fd, char **line);
int		read_loop(int fd, char **line);

#endif
