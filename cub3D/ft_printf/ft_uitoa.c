#include "libftprintf.h"

static size_t	ft_len(unsigned int nbr)
{
	size_t len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char			*ft_uitoa(unsigned int n)
{
	char	*buff;
	size_t	i;

	i = ft_len(n);
	if (!(buff = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	if (n == 0)
		buff[0] = '0';
	while (n > 0)
	{
		buff[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (buff);
}
