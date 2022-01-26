#include "libftprintf.h"

t_arg	*ft_new_arg(char **fmt, va_list ap)
{
	t_arg *arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->flag = ft_get_flag(fmt);
	arg->width = ft_get_width(fmt, ap);
	arg->precision = ft_get_precision(fmt, ap);
	arg->type = ft_get_type(fmt);
	arg->sign = 0;
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->flag = 1;
	}
	return (arg);
}
