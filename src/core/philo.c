#include "../../includes/philo.h"
#include "../../includes/utils.h"
#include <unistd.h>

static int simulation_should_continue(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_mutex);
	if (philo->data->died_flag || philo->data->all_ate_flag)
	{
		pthread_mutex_unlock(&philo->data->data_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->data_mutex);
	return (1);
}

static void philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		if (!philo->right_fork)
		{
			usleep(philo->data->time_to_die * 1000 + 1000);
			pthread_mutex_unlock(philo->left_fork);
			return;
		}
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		if (!philo->right_fork)
		{
			pthread_mutex_lock(philo->left_fork);
			print_status(philo, "has taken a fork");
			usleep(philo->data->time_to_die * 1000 + 1000);
			pthread_mutex_unlock(philo->left_fork);
			return;
		}
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}

	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->last_meal = timestamp();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->data_mutex);

	usleep(philo->data->time_to_eat * 1000);

	pthread_mutex_unlock(philo->left_fork);
	if (philo->right_fork)
		pthread_mutex_unlock(philo->right_fork);
}

static void philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

static void philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void *philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		usleep(philo->data->time_to_die * 1000 + 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}

	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat / 2 * 1000); 

	while (simulation_should_continue(philo))
	{
		philo_eat(philo);
		if (!simulation_should_continue(philo))
			break;
		philo_sleep(philo);
		if (!simulation_should_continue(philo))
			break;
		philo_think(philo);
	}
	return (NULL);
}
