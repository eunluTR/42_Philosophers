#include "philo.h"

t_bool	get_error_flag(t_shared *data, t_locks *locks)
{
	t_bool	val;

	pthread_mutex_lock(&locks->mtx_error);
	val = data->flag_error;
	pthread_mutex_unlock(&locks->mtx_error);
	return (val);
}


t_bool	get_death_flag(t_shared *data, t_locks *locks)
{
	t_bool	val;

	pthread_mutex_lock(&locks->mtx_death);
	val = data->flag_death;
	pthread_mutex_unlock(&locks->mtx_death);
	return (val);
}


t_bool	get_full_flag(t_shared *data, t_locks *locks)
{
	t_bool	val;

	pthread_mutex_lock(&locks->mtx_full);
	val = data->flag_full;
	pthread_mutex_unlock(&locks->mtx_full);
	return (val);
}
