#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;

	str = (0);
	while (*s)
	{
		if (*s == (char)c)
			str = (char*)s;
		s++;
	}
	if (str)
		return (str);
	if ((char)c == '\0')
		return ((char*)s);
	return (0);
}
