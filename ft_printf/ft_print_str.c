#include "libftprintf.h"

static void	ft_print_(t_arg *arg, char *str, int *length)
{
	if (arg->flag == 0)
		while (arg->width > *length)
		{
			ft_putchar_fd(' ', 1);
			(*length)++;
		}
	ft_putstr_fd(str, 1);
	if (arg->flag == 1)
		while (arg->width > *length)
		{
			ft_putchar_fd(' ', 1);
			(*length)++;
		}
}

int			ft_print_str(t_arg *arg, va_list ap)
{
	char	*str;
	int		length;
	int		flag;

	flag = 0;
	str = va_arg(ap, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
		flag = 1;
	}
	length = ft_strlen(str);
	if (arg->precision > -1 && arg->precision < length)
	{
		str = ft_str_cut(str, 0, arg->precision, &flag);
		length = arg->precision;
		flag = 1;
	}
	ft_print_(arg, str, &length);
	if (flag == 1)
		free(str);
	return (length);
}
