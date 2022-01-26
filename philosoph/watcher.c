#include "philo.h"

static int	is_full(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->args->number_of_philos)
		if (philos[i].eat_status != FULL)
			return (1);
	return (0);
}

void	launch_watcher(t_philo *philos)
{
	int	i;
	int	time;

	while (!philos->args->is_dead)
	{
		i = -1;
		while (++i < philos->args->number_of_philos)
		{
			if (philos[i].eat_status != FULL)
			{
				time = get_time() - philos[i].eat_time;
				if (time >= philos[i].args->time_to_die + 10)
				{
					philos->args->is_dead = 1;
					print_status(philos, DIE);
				}
			}
			else
			{
				if (!is_full(philos))
					return ;
			}
		}
	}
}
