#include "utils.h"

static t_bool	one_philo_eating(t_philo *ph)
{
	display_status(ph, ST_PICKING_UP_FORK);
	return (FALSE);
}

static t_bool	pick_up_forks(t_philo *ph)
{
	lock_the_mutex(ph->first_fork);
	lock_the_mutex(ph->last_fork);
	if (!display_status(ph, ST_PICKING_UP_FORK) || !display_status(ph, ST_PICKING_UP_FORK))
	{
		unlock_the_mutex(ph->last_fork);
		unlock_the_mutex(ph->first_fork);
		return (FALSE);
	}
	return (TRUE);
}

static void	put_down_forks(t_philo *ph)
{
	unlock_the_mutex(ph->last_fork);
	unlock_the_mutex(ph->first_fork);
}

static void	check_satisfaction(t_philo *ph)
{
	if (ph->data.eat_limit == -1)
		return ;
	if (ph->data.eat_count >= ph->data.eat_limit)
	{
		pthread_mutex_lock(&ph->locks->mtx_full);
		ph->is_full = TRUE;
		pthread_mutex_unlock(&ph->locks->mtx_full);
	}
}


t_bool	eating(t_philo *ph)
{
	t_ms *ref;

	if (ph->data.philo_count == 1)
		return (one_philo_eating(ph));
	if (!pick_up_forks(ph))
		return (FALSE);
	if (!display_status(ph, ST_EATING))
	{
		put_down_forks(ph);
		return (FALSE);
	}
	elapse_time(ph->shared, ph->locks, ph->data.meal_time);
	ref = &ph->data.last_meal_time;
	pthread_mutex_lock(&ph->locks->mtx_meal);
	*ref = get_timestamp(ph->shared, ph->locks);
	ph->data.eat_count += 1;
	pthread_mutex_unlock(&ph->locks->mtx_meal);
	check_satisfaction(ph);
	put_down_forks(ph);
	return (TRUE);
}
