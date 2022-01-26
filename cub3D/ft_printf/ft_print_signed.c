#include "libftprintf.h"

int	ft_print_signed(t_arg *arg, va_list ap)
{
	int		num;
	char	*tmp;
	int		length;

	length = 0;
	num = va_arg(ap, int);
	if (num < 0)
		arg->sign = 1;
	if (num == 0 && arg->precision == 0)
		tmp = NULL;
	else
		tmp = ft_sitoa(num);
	length = ft_strlen(tmp);
	length = ft_print_number(arg, tmp, &length);
	return (length);
}
