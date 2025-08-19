#include "philo.h"

static void		*run_dining(void *arg);
static void		join_threads(t_table *table);
static t_bool	start_threads(t_table *table);
static void		cleanup_partial(t_philo *philos, size_t count);

static t_bool	start_threads(t_table *table)
{
	size_t i;

	i = 0;
	while (i < table->data.philo_count)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &run_dining, \
				&table->philos[i]) != SUCCESS)
		{
			set_error_flag(table->shared, table->locks, TRUE);
			cleanup_partial(table->philos, i);
			return (display_err_msg(ERR_PTHREAD_CREATE));
		}
		i++;
	}
	if (pthread_create(&table->monitor, NULL, &monitor, table) != SUCCESS)
	{
		set_error_flag(table->shared, table->locks, TRUE);
		return (display_err_msg(ERR_PTHREAD_CREATE));
	}
	return (TRUE);
}

static void	join_threads(t_table *table)
{
	size_t i;
	i = 0;
	while (i < table->data.philo_count)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
}

static void	*run_dining(void *arg)
{
	t_philo *ph;

	ph = (t_philo *)arg;
	if (get_error_flag(ph->shared, ph->locks))
		return (NULL);
	if (ph->id % 2 == 0)
		usleep(100);
	start_routine(ph);
	return (NULL);
}

static void	cleanup_partial(t_philo *philos, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		if (philos[i].thread)
			pthread_join(philos[i].thread, NULL);
		i++;
	}
}


t_bool	init_simulation(t_table *table)
{
	size_t	i;

	i = 0;
	table->data.start_ts = get_timestamp(table->shared, table->locks);
	while (i < table->data.philo_count)
	{
		table->philos[i].data.last_meal_time = table->data.start_ts;
		table->philos[i].data.start_ts = table->data.start_ts;
		i++;
	}
	if (!start_threads(table))
		return (FALSE);
	join_threads(table);
	return (TRUE);
}
