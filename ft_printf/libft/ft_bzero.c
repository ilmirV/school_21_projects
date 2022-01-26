#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset((char*)s, '\0', n);
}
