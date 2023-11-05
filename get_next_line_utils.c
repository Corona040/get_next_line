/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:11:33 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/05 15:32:54 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	size_s;
	char	*dup;

	size_s = ft_strlen(s) + 1;
	dup = ft_calloc(size_s, sizeof(char));
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, size_s);
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!join)
		return (0);
	ft_strlcat(join, s1, len_s1 + 1);
	ft_strlcat(join, s2, len_s1 + len_s2 + 1);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	while (*s != uc && *s)
		s++;
	if (*s == uc)
		return ((char *)s);
	else
		return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	len_src;

	len_src = ft_strlen(src);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (size > 0 && nmemb > ((size_t) -1) / size)
		return (0);
	array = malloc(nmemb * size);
	if (!array)
		return (0);
	ft_bzero(array, nmemb * size);
	return (array);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	n;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	n = 0;
	while (n + len_dst + 1 < size && *(src + n))
	{
		*(dst + len_dst + n) = *(src + n);
		n++;
	}
	*(dst + len_dst + n) = '\0';
	if (size < len_dst)
		return (len_src + size);
	else
		return (len_dst + len_src);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((char *)(s + i++)) = c;
	return (s);
}
