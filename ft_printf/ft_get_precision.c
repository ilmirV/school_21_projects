#include "libftprintf.h"

int	ft_get_precision(char **fmt, va_list ap)
{
	int	precision;

	precision = 0;
	if (**fmt != '.')
		return (-1);
	*fmt += 1;
	if (**fmt == '*')
	{
		*fmt += 1;
		return (precision = va_arg(ap, int));
	}
	precision = ft_get_number(fmt);
	return (precision);
}
