#include "libft.h"
#include <stdio.h>

char	*ft_strjoinnul(char const *s1, char const *s2)
{
	char *join;

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
