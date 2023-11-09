/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorona- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:36:33 by ecorona-          #+#    #+#             */
/*   Updated: 2023/11/09 16:36:49 by ecorona-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoinnul(char const *s1, char const *s2)
{
	char	*join;

	join = 0;
	if (s1 && s2)
		join = ft_strjoin(s1, s2);
	else if (!s1 && !s2)
		join = 0;
	else if (!s1)
		join = ft_strjoin("", s2);
	else if (!s2)
		join = ft_strjoin(s1, "");
	if (!join)
		return (0);
	return (join);
}
