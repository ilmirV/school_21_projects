#include "libftprintf.h"

int	ft_print_char(t_arg *arg, va_list ap)
{
	char	c;
	int		length;

	length = 1;
	if (arg->width)
		length = arg->width;
	c = va_arg(ap, int);
	if (arg->flag == 0)
		while (arg->width-- > 1)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (arg->flag == 1)
		while (arg->width-- > 1)
			ft_putchar_fd(' ', 1);
	return (length);
}
