#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
				str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - '0');
	num *= sign;
	return (num);
}
