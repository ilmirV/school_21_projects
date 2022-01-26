#include "libftprintf.h"

static size_t	ft_len(int num)
{
	size_t len;

	len = 0;
	if (num == 0)
		len++;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char			*ft_sitoa(int n)
{
	char	*buff;
	size_t	i;

	if (n == -2147483648)
		return (buff = ft_strdup("2147483648"));
	i = ft_len(n);
	if (!(buff = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	if (n == 0)
		buff[0] = '0';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		buff[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (buff);
}
