/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:47:48 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/10 12:38:27 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char	*ft_strjoinnul(char *s1, char *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;
	size_t	n;

	len_s1 = 0;
	len_s2 = 0;
	while (s1 && *(s1 + len_s1))
		len_s1++;
	while (s2 && *(s2 + len_s2))
		len_s2++;
	join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!join)
		return (0);
	len_s1 = 0;
	while (s1 && *s1)
		*(join + len_s1++) = *s1++;
	len_s2 = 0;
	while (s2 && *s2)
		*(join + len_s1 + len_s2++) = *s2++;
	*(join + len_s1 + len_s2) = '\0';
	return (join);
}

int	get_char_idx(char *str, int c)
{
	int i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	if (*(str + i))
		return (i);
	else
		return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	len_src;

	len_src = 0;
	while (*(src + len_src))
		len_src++;
	if (size == 0)
		return (len_src);
	n = 0;
	while (n + 1 < size && *(src + n))
	{
		*(dst + n) = *(src + n);
		n++;
	}
	*(dst + n) = '\0';
	return (len_src);
}

void	split_at_first(char	*src, char *dest1, char dest2, int c)
{

}
*/
