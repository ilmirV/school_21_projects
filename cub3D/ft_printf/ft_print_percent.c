#include "libftprintf.h"

int	ft_print_percent(t_arg *arg)
{
	int length;

	length = 1;
	if (arg->width)
		length = arg->width;
	if (arg->flag == 0)
		while (--arg->width > 0)
			ft_putchar_fd(' ', 1);
	if (arg->flag == 2)
		while (--arg->width > 0)
			ft_putchar_fd('0', 1);
	ft_putchar_fd('%', 1);
	if (arg->flag == 1)
		while (--arg->width > 0)
			ft_putchar_fd(' ', 1);
	return (length);
}
