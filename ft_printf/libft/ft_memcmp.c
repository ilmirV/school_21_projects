#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				dif;
	unsigned char	*str1;
	unsigned char	*str2;

	dif = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n--)
	{
		dif = *(str1++) - *(str2++);
		if (dif != 0)
			return (dif);
	}
	return (dif);
}
