/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:46:33 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:46:37 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	free_mutex(pthread_mutex_t *mtx, t_bool *is_init)
{
	if (*is_init)
	{
		if (pthread_mutex_destroy(mtx) != SUCCESS)
			display_err_msg(ERR_MTX_DESTROY);
	}
}

static void	free_locks(t_locks *locks)
{
	if (!locks)
		return ;
	free_mutex(&locks->mtx_meal, &locks->init_meal);
	free_mutex(&locks->mtx_full, &locks->init_full);
	free_mutex(&locks->mtx_death, &locks->init_death);
	free_mutex(&locks->mtx_print, &locks->init_print);
	free_mutex(&locks->mtx_error, &locks->init_error);
	free(locks);
}

static void	free_philos(t_philo *philos)
{
	size_t	i;
	size_t	len;

	if (!philos)
		return ;
	len = philos[0].data.philo_count;
	i = 0;
	while (i < len)
	{
		if (philos[i].right_fork)
		{
			pthread_mutex_destroy(philos[i].right_fork);
			free(philos[i].right_fork);
		}
		philos[i].right_fork = NULL;
		philos[i].left_fork = NULL;
		philos[i].first_fork = NULL;
		philos[i].last_fork = NULL;
		philos[i].shared = NULL;
		philos[i].locks = NULL;
		i++;
	}
	free(philos);
}

void	free_table(t_table *table)
{
	if (!table)
		return ;
	free_locks(table->locks);
	table->locks = NULL;
	free(table->shared);
	table->shared = NULL;
	free_philos(table->philos);
	free(table);
}
