#include "libftprintf.h"

int	ft_parse(char **fmt, va_list ap)
{
	t_arg	*arg;
	int		length;

	length = 0;
	arg = ft_new_arg(fmt, ap);
	if (!arg)
		return (-1);
	if (arg->type == 'c')
		length += ft_print_char(arg, ap);
	if (arg->type == 's')
		length += ft_print_str(arg, ap);
	if (arg->type == 'd' || arg->type == 'i')
		length += ft_print_signed(arg, ap);
	if (arg->type == 'u' || arg->type == 'x' || arg->type == 'X')
		length += ft_print_unsigned(arg, ap);
	if (arg->type == 'p')
		length += ft_print_ptr(arg, ap);
	if (arg->type == '%')
		length += ft_print_percent(arg);
	free(arg);
	return (length);
}
