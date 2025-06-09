#include "../includes/philo.h"
#include "../includes/utils.h"

int is_number(const char *str)
{
	int i = 0;
	if (!str || !str[0])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void assign_philosophers(t_data *data)
{
	int i;

	for (i = 0; i < data->philo_count; i++)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
	}
}