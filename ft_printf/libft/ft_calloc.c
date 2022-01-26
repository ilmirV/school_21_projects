#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *str;

	if (!(str = (void*)malloc(count * size)))
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
