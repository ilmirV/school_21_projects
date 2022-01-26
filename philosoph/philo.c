#include "philo.h"

void	*simulate(void *arg)
{
	int		number;
	t_philo	*philo;

	philo = arg;
	if (!(philo->id % 2))
		ft_usleep(philo->args->time_to_sleep - 10);
	number = 0;
	while (!philo->args->is_dead)
	{
		to_eat(philo);
		if (philo->args->number_of_meals)
		{
			number++;
			if (philo->args->number_of_meals == number)
			{
				philo->eat_status = FULL;
				print_status(philo, FULL);
				return (NULL);
			}
		}
		to_sleep(philo);
		to_think(philo);
	}
	return (NULL);
}

static t_philo	*create_philos(t_args *args, pthread_mutex_t *mutexes,
								pthread_mutex_t *status)
{
	int		i;
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * args->number_of_philos);
	if (!philos)
		return (NULL);
	i = -1;
	while (++i < args->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].args = args;
		philos[i].start_time = get_time();
		philos[i].eat_time = get_time();
		philos[i].eat_status = 0;
		philos[i].status = &status[0];
		philos[i].die = &status[1];
		philos[i].left = &mutexes[i];
		philos[i].right = &mutexes[(i + 1) % args->number_of_philos];
	}
	return (philos);
}

static int	create_threads(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->args->number_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, simulate, &philos[i]))
			return (print_error("Can't create thread\n"));
	}
	i = -1;
	while (++i < philos->args->number_of_philos)
	{
		if (pthread_detach(philos[i].thread))
			return (print_error("Can't join thread\n"));
	}
	return (0);
}

static pthread_mutex_t	*create_mutexes(t_args *args)
{
	int				i;
	pthread_mutex_t	*mutexes;

	mutexes = malloc(sizeof(pthread_mutex_t) * args->number_of_philos);
	if (!mutexes)
		return (NULL);
	i = -1;
	while (++i < args->number_of_philos)
		if (pthread_mutex_init(&mutexes[i], NULL))
			return (NULL);
	return (mutexes);
}

int	main(int argc, char **argv)
{
	t_args			args;
	t_philo			*philos;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	status[2];

	if (argc != 5 && argc != 6)
		return (print_error("Wrong number of arguments\n"));
	if (validate_args(argv))
		return (print_error("Invalid argument\n"));
	parse_args(argv, &args);
	if (args.number_of_philos == 0)
		return (print_error("Invalid argument\n"));
	mutexes = create_mutexes(&args);
	if (!mutexes)
		return (print_error("Can't create mutexes\n"));
	pthread_mutex_init(&status[0], NULL);
	pthread_mutex_init(&status[1], NULL);
	philos = create_philos(&args, mutexes, status);
	if (!philos)
		return (print_error("Can't create philosophers\n"));
	if (create_threads(philos))
		return (1);
	launch_watcher(philos);
	return (0);
}
