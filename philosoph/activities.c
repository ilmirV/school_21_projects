#include "philo.h"

void	to_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	print_status(philo, FORK);
	print_status(philo, EAT);
	philo->eat_time = get_time();
	ft_usleep(philo->args->time_to_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	to_sleep(t_philo *philo)
{
	print_status(philo, SLEEP);
	ft_usleep(philo->args->time_to_sleep);
}

void	to_think(t_philo *philo)
{
	print_status(philo, THINK);
}
