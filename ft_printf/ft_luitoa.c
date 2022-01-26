#include "libftprintf.h"

static size_t	ft_lulen(unsigned long int nbr)
{
	size_t len;

	len = 0;
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

char			*ft_luitoa(unsigned long int num)
{
	char				*buff;
	size_t				i;
	unsigned long int	rem;

	i = ft_lulen(num);
	if (!(buff = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	if (num == 0)
		buff[0] = '0';
	while (num > 0)
	{
		rem = num % 16;
		if (rem > 9)
			buff[--i] = rem + 87;
		else
			buff[--i] = rem + '0';
		num /= 16;
	}
	return (buff);
}
