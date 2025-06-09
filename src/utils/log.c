#include "../includes/philo.h"
#include "utils.h"
#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

long long timestamp(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void print_status(t_philo *philo, char *msg)
{
	long long now;

	pthread_mutex_lock(&philo->data->log_mutex);
	now = timestamp() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->data_mutex);
	if (!philo->data->died_flag || (msg && msg[0] == 'd' && msg[1] == 'i' && msg[2] == 'e' && msg[3] == 'd'))
	{
		if (!(philo->data->died_flag && !(msg && msg[0] == 'd' && msg[1] == 'i' && msg[2] == 'e' && msg[3] == 'd')))
 			printf("%lld %d %s\n", now, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->data_mutex);
	fflush(stdout);
	pthread_mutex_unlock(&philo->data->log_mutex);
}
