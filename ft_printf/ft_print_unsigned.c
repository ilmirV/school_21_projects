#include "libftprintf.h"

int	ft_print_unsigned(t_arg *arg, va_list ap)
{
	int				length;
	unsigned int	num;
	char			*str;

	length = 0;
	num = va_arg(ap, unsigned int);
	str = NULL;
	if (num > 0 || (num == 0 && arg->precision != 0))
	{
		if (arg->type == 'u')
			str = ft_uitoa(num);
		if (arg->type == 'x' || arg->type == 'X')
			str = ft_xitoa(num, arg);
	}
	length = ft_strlen(str);
	length = ft_print_number(arg, str, &length);
	return (length);
}
