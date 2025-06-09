#include "../includes/philo.h"
#include "utils.h"
#include <stdio.h>

int parse_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: Wrong number of arguments\n"), 0);
	for (int i = 1; i < argc; i++)
	{
		if (!is_number(argv[i]))
			return (printf("Error: Arguments must be positive integers\n"), 0);
	}
	data->philo_count = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->must_eat = (argc == 6) ? atoi(argv[5]) : -1;
	if (data->philo_count < 1 || data->time_to_die < 1 || data->time_to_eat < 1 || data->time_to_sleep < 1)
		return (printf("Error: Arguments must be greater than 0\n"), 0);
	if (argc == 6 && data->must_eat < 1)
		return (printf("Error: number_of_times_each_philosopher_must_eat must be > 0\n"), 0);
	return (1);
}
