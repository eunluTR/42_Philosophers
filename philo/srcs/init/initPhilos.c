#include "utils.h"

static t_bool	init_one(t_philo *ph, char **argv, int argc);

void	init_custom_data(t_custom *data, char **argv, int argc)
{
	data->eat_count = 0;
	data->lifetime = ft_atoui(argv[2]);
	data->meal_time = ft_atoui(argv[3]);
	data->sleep_time = ft_atoui(argv[4]);
	if (argc == 5)
		data->eat_limit = -1;
	else
		data->eat_limit = ft_atoui(argv[5]);
	data->last_meal_time = 0;
	data->start_ts = 0;
}

t_bool	init_philos(t_philo **philos, char **argv, int argc)
{
	int		i;
	int		n;
	t_philo	*arr;

	n = (int)ft_atoui(argv[1]);
	*philos = (t_philo *)ft_calloc(n, sizeof(t_philo));
	arr = *philos;
	if (!arr)
		return (display_err_msg(ERR_ALLOC));
	i = 0;
	while (i < n)
	{
		if (!init_one(&arr[i], argv, argc))
			return (FALSE);
		arr[i].id = i + 1;
		arr[i].data.philo_count = n;
		i++;
	}
	return (TRUE);
}

static t_bool	init_one(t_philo *ph, char **argv, int argc)
{
	memset(ph, 0, sizeof(t_philo));
	init_custom_data(&ph->data, argv, argc);
	ph->right_fork = (t_mutex *)ft_calloc(1, sizeof(t_mutex));
	if (!ph->right_fork)
		return (display_err_msg(ERR_ALLOC));
	if (pthread_mutex_init(ph->right_fork, NULL) != SUCCESS)
		return (display_err_msg(ERR_MTX_INIT));
	return (TRUE);
}

void	set_left_forks(t_philo *philos)
{
	size_t	i;
	size_t	len;

	len = philos[0].data.philo_count;
	if (len == 1)
	{
		philos[0].left_fork = NULL;
		return ;
	}
	i = 0;
	while (i < len)
	{
		philos[i].left_fork = philos[(i + 1) % len].right_fork;
		i++;
	}
}

void	set_fork_priority(t_philo *philos)
{
	size_t	i;
	size_t	len;

	len = philos[0].data.philo_count;
	i = 0;
	while (i < len)
	{
		if (i % 2 == 0)
		{
			philos[i].first_fork = philos[i].right_fork;
			philos[i].last_fork = philos[i].left_fork;
		}
		else
		{
			philos[i].first_fork = philos[i].left_fork;
			philos[i].last_fork = philos[i].right_fork;
		}
		i++;
	}
}
