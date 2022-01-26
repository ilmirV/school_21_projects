#include "libftprintf.h"

char	*ft_str_cut(char const *s, unsigned int start, size_t len, int *flag)
{
	char *buff;

	if (!s)
		return (NULL);
	buff = ft_calloc(sizeof(char), len + 1);
	if (buff)
	{
		if (start >= ft_strlen(s))
			return (buff);
		ft_memcpy(buff, ((char*)s + start), len);
		if (*flag == 1)
			free((char*)s);
		return (buff);
	}
	return (NULL);
}
