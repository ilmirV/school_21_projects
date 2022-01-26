#include "libftprintf.h"

char	ft_get_type(char **fmt)
{
	char type;

	type = 0;
	if (ft_strchr("cspdiuxX%", **fmt))
		type = **fmt;
	return (type);
}
