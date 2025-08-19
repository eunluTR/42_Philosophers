#include "utils.h"

static t_bool	init_locks(t_locks **locks);
static t_bool	init_shared(t_shared **shared);
static t_bool	init_mutex(pthread_mutex_t *mtx, t_bool *flag);
static void		set_common_data(t_philo *philos, t_shared *shared, t_locks *locks);

static void		set_defaults(t_table *table)
{
	if (!table)
		return ;
	table->philos = NULL;
	table->locks = NULL;
	table->shared = NULL;
}

t_table	*init_table(char **argv, int argc)
{
	t_table *table;

	table = (t_table *)ft_calloc(1, sizeof(t_table));
	if (!table)
	{
		display_err_msg(ERR_ALLOC);
		return (NULL);
	}
	set_defaults(table);
	table->data.philo_count = ft_atoui(argv[1]);
	init_custom_data(&table->data, argv, argc);
	if (!init_locks(&table->locks) || !init_shared(&table->shared) \
		|| !init_philos(&table->philos, argv, argc))
	{
		free_table(table);
		return (NULL);
	}
	set_left_forks(table->philos);
	set_fork_priority(table->philos);
	set_common_data(table->philos, table->shared, table->locks);
	return (table);
}

static void	set_common_data(t_philo *philos, t_shared *shared, t_locks *locks)
{
	size_t	i;
	size_t	len;

	len = philos[0].data.philo_count;
	i = 0;
	while (i < len)
	{
		philos[i].locks = locks;
		philos[i].shared = shared;
		i++;
	}
}

static t_bool	init_mutex(pthread_mutex_t *mtx, t_bool *flag)
{
	if (pthread_mutex_init(mtx, NULL) != SUCCESS)
		return (FALSE);
	*flag = TRUE;
	return (TRUE);
}

static t_bool	init_locks(t_locks **locks)
{
	t_locks *tmp;

	*locks = (t_locks *)ft_calloc(1, sizeof(t_locks));
	if (!*locks)
		return (display_err_msg(ERR_ALLOC));
	tmp = *locks;
	if (!init_mutex(&tmp->mtx_death, &tmp->init_death))
		return (display_err_msg(ERR_MTX_INIT));
	if (!init_mutex(&tmp->mtx_full, &tmp->init_full))
		return (display_err_msg(ERR_MTX_INIT));
	if (!init_mutex(&tmp->mtx_print, &tmp->init_print))
		return (display_err_msg(ERR_MTX_INIT));
	if (!init_mutex(&tmp->mtx_error, &tmp->init_error))
		return (display_err_msg(ERR_MTX_INIT));
	if (!init_mutex(&tmp->mtx_meal, &tmp->init_meal))
		return (display_err_msg(ERR_MTX_INIT));
	return (TRUE);
}

static t_bool	init_shared(t_shared **shared)
{
	*shared = (t_shared *)ft_calloc(1, sizeof(t_shared));
	if (!*shared)
		return (display_err_msg(ERR_ALLOC));
	return (TRUE);
}
