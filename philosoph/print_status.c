#include "philo.h"

void	print_status(t_philo *philo, int status)
{
	int	time;

	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->status);
	if (status == FORK)
		printf("%d %d has taken a fork\n", time, philo->id);
	else if (status == EAT)
		printf("%d %d is eating\n", time, philo->id);
	else if (status == SLEEP)
		printf("%d %d is sleeping\n", time, philo->id);
	else if (status == THINK)
		printf("%d %d is thinking\n", time, philo->id);
	else if (status == DIE)
		printf("%d %d is died\n", time, philo->id);
	else if (status == FULL)
		printf("%d %d is full\n", time, philo->id);
	pthread_mutex_unlock(philo->status);
}
