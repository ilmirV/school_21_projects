#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((void*)s);
		s++;
	}
	if (*s == (char)c)
		return ((void*)s);
	return (0);
}
