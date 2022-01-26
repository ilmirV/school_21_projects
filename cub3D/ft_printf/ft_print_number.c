#include "libftprintf.h"

int	ft_print_number(t_arg *arg, char *tmp, int *length)
{
	while (arg->precision > (*length)++)
		tmp = ft_str_join("0", tmp);
	*length = ft_strlen(tmp);
	if (arg->sign == 1 && !(arg->flag == 2 && arg->width > *length
				&& arg->precision <= -1))
	{
		tmp = ft_str_join("-", tmp);
		(*length)++;
	}
	if (arg->flag == 0 || (arg->flag == 2 && arg->precision > -1))
		while (arg->width > (*length)++)
			ft_putchar_fd(' ', 1);
	if (arg->flag == 2 && arg->precision <= -1)
		while (arg->width > (*length)++)
			tmp = ft_str_join("0", tmp);
	if (tmp != NULL && arg->sign == 1 && arg->flag == 2 && arg->precision <= -1)
		tmp[0] = '-';
	ft_putstr_fd(tmp, 1);
	if (arg->flag == 1)
		while (arg->width > (*length)++)
			ft_putchar_fd(' ', 1);
	free(tmp);
	return (--(*length));
}
