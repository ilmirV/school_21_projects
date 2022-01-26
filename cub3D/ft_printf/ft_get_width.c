#include "libftprintf.h"

int	ft_get_width(char **fmt, va_list ap)
{
	int	width;

	width = 0;
	if (**fmt == '*')
	{
		*fmt += 1;
		return (width = va_arg(ap, int));
	}
	width = ft_get_number(fmt);
	return (width);
}
