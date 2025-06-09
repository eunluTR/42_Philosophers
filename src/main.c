#include "../includes/philo.h"
#include "../includes/utils.h"

extern void *philo_routine(void *arg);

static int check_all_ate(t_data *data)
{
	int i;
	int all_ate_count;

	if (data->must_eat_count == -1)
		return (0);
	i = 0;
	all_ate_count = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->data_mutex);
		if (data->philos[i].eat_count >= data->must_eat_count)
			all_ate_count++;
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	if (all_ate_count == data->philo_count)
	{
		pthread_mutex_lock(&data->data_mutex);
		data->all_ate_flag = 1;
		pthread_mutex_unlock(&data->data_mutex);
		return (1);
	}
	return (0);
}

static int check_death(t_data *data)
{
	int i;
	long long current_time;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->data_mutex);
		current_time = timestamp();
		if (data->died_flag)
		{
			pthread_mutex_unlock(&data->data_mutex);
			return (1);
		}
		if ((current_time - data->philos[i].last_meal) > data->time_to_die)
		{
			data->died_flag = 1;
			pthread_mutex_unlock(&data->data_mutex);
			pthread_mutex_lock(&data->log_mutex);
			printf("%lld %d died\\n", current_time - data->start_time, data->philos[i].id);
			pthread_mutex_unlock(&data->log_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->data_mutex);
		i++;
	}
	return (0);
}

void *monitor_routine(void *arg)
{
	t_data *data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_death(data) || check_all_ate(data))
			break;
		usleep(1000);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_data data;
	int i;
	pthread_t monitor_thread_id;

	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo num_philos time_die time_eat time_sleep [must_eat_times]\\n");
		return (1);
	}
	if (!parse_args(argc, argv, &data))
		return (1);
	
	data.start_time = timestamp();

	if (!init_data(&data))
	{
		printf("Error: Data initialization failed\\n");
		destroy_data(&data);
		return (1);
	}

	i = 0;
	while (i < data.philo_count)
	{
		if (pthread_create(&data.threads[i], NULL, philo_routine, &data.philos[i]) != 0)
		{
			destroy_data(&data);
			return (1);
		}
		i++;
	}
	if (pthread_create(&monitor_thread_id, NULL, monitor_routine, &data) != 0)
	{
		destroy_data(&data);
		return (1);
	}

	i = 0;
	while (i < data.philo_count)
	{
		pthread_join(data.threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread_id, NULL);
	
	destroy_data(&data);
	return (0);
}
