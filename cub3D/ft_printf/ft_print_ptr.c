#include "libftprintf.h"

int	ft_print_ptr(t_arg *arg, va_list ap)
{
	int					length;
	unsigned long int	num;
	char				*str;

	length = 0;
	num = va_arg(ap, unsigned long int);
	str = ft_strdup("0x");
	if (num > 0 || (num == 0 && arg->precision != 0))
	{
		free(str);
		str = ft_luitoa(num);
		str = ft_str_join("0x", str);
	}
	length = ft_strlen(str);
	length = ft_print_number(arg, str, &length);
	return (length);
}
