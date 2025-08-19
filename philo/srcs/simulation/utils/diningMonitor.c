#include "philo.h"

static t_bool	are_all_full(t_table *table)
{
	size_t	i;
	size_t	full;
	size_t	total;
	t_bool	*full_ref;

	total = table->data.philo_count;
	full = 0;
	i = 0;
	while (i < total)
	{
		full_ref = &table->philos[i].is_full;
		lock_the_mutex(&table->locks->mtx_full);
		if (*full_ref)
			full += 1;
		unlock_the_mutex(&table->locks->mtx_full);
		i++;
	}
	return (full == total);
}

static t_ms	get_last_meal_time_safe(t_philo *ph)
{
	t_ms v;
	pthread_mutex_lock(&ph->locks->mtx_meal);
	v = ph->data.last_meal_time;
	pthread_mutex_unlock(&ph->locks->mtx_meal);
	return (v);
}

static t_bool	is_any_dead(t_table *table)
{
	size_t	i;
	t_ms	now;
	t_ms	delta;
	t_philo	*ph;

	i = 0;
	while (i < table->data.philo_count)
	{
		ph = &table->philos[i];
		now = get_timestamp(table->shared, table->locks);
		delta = now - get_last_meal_time_safe(ph);
		if (delta > table->data.lifetime)
		{
			display_status(ph, ST_DEAD);
			set_death_flag(table->shared, table->locks, TRUE);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	*monitor(void *arg)
{
	t_table *table;

	table = (t_table *)arg;
	while (TRUE)
	{
		if (get_error_flag(table->shared, table->locks))
			break ;
		if (are_all_full(table))
		{
			set_full_flag(table->shared, table->locks, TRUE);
			break ;
		}
		if (is_any_dead(table))
			break ;
	}
	return (NULL);
}
