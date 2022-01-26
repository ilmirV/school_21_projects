#include "libftprintf.h"

char	*ft_str_join(char const *s1, char const *s2)
{
	char	*buff;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buff = calloc(sizeof(char), len_s1 + len_s2 + 1);
	if (buff != NULL)
	{
		ft_strlcpy(buff, s1, len_s1 + 1);
		ft_strlcpy(buff + len_s1, s2, len_s2 + 1);
		free((char*)s2);
		return (buff);
	}
	return (NULL);
}
