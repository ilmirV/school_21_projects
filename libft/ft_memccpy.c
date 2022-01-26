#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	i = 0;
	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	while (n--)
	{
		p_dst[i] = p_src[i];
		if (p_dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
