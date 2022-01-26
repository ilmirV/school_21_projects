#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
{
	int		length;
	va_list	ap;
	int		res;

	length = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if ((res = ft_parse((char **)&fmt, ap)) == -1)
				return (-1);
			length += res;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			length++;
		}
		fmt++;
	}
	va_end(ap);
	return (length);
}
