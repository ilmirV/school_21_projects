#include "libftprintf.h"

static size_t	ft_ulen(unsigned int nbr)
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

char			*ft_xitoa(unsigned int num, t_arg *arg)
{
	char			*buf;
	size_t			i;
	unsigned int	rem;

	i = ft_ulen(num);
	if (!(buf = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	if (num == 0)
		buf[0] = '0';
	while (num > 0)
	{
		rem = num % 16;
		if (rem > 9)
		{
			if (arg->type == 'X')
				buf[--i] = rem + 55;
			else
				buf[--i] = rem + 87;
		}
		else
			buf[--i] = rem + '0';
		num /= 16;
	}
	return (buf);
}
