#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char *ptr;

	ptr = (char*)b;
	while (len--)
		*(ptr++) = (unsigned char)c;
	return (b);
}
