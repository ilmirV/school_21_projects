#include "libftprintf.h"

int	ft_get_number(char **fmt)
{
	int		number;
	int		length;
	char	*tmp;

	number = 0;
	length = 0;
	tmp = *fmt;
	while (ft_isdigit(**fmt))
	{
		*fmt += 1;
		length++;
	}
	if (length != 0)
	{
		tmp = ft_substr(tmp, 0, length);
		number = ft_atoi(tmp);
		free(tmp);
	}
	return (number);
}
