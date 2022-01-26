#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time();
	while ((get_time() - time) < ms)
		usleep(100);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			dig;
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	dig = 0;
	while (*str && (*str == '\f' || *str == '\t' || *str == ' ' || \
				*str == '\n' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (num * sign) > MAXINT || (num * sign) < MININT)
			ft_error();
		str++;
	}
	return ((int)(num * sign));
}
