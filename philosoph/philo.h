#ifndef PHILO_H
# define PHILO_H

# define MAXINT 2147483647
# define MININT -2147483648
# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5
# define FULL 6

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	int	is_dead;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				eat_status;
	long int		start_time;
	long int		eat_time;
	t_args			*args;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*status;
	pthread_mutex_t	*die;
}	t_philo;

int		ft_atoi(const char *str);
void	ft_error(void);
int		ft_isdigit(int c);
int		print_error(char *str);
void	to_eat(t_philo *philo);
void	to_sleep(t_philo *philo);
void	to_think(t_philo *philo);
void	print_status(t_philo *philo, int status);
long	get_time(void);
void	ft_usleep(int ms);
void	launch_watcher(t_philo *philos);
void	parse_args(char **argv, t_args *args);
int		validate_args(char **argv);

#endif