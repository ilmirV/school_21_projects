#include "libftprintf.h"

int	ft_get_flag(char **fmt)
{
	int flag;

	flag = 0;
	while (ft_strchr("0-", **fmt))
	{
		if (**fmt == '-')
			flag = 1;
		else if (**fmt == '0')
			if (flag == 0)
				flag = 2;
		*fmt += 1;
	}
	return (flag);
}
