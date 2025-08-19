/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncSet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:31:34 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:31:34 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_error_flag(t_shared *data, t_locks *locks, t_bool val)
{
	pthread_mutex_lock(&locks->mtx_error);
	data->flag_error = val;
	pthread_mutex_unlock(&locks->mtx_error);
}

void	set_death_flag(t_shared *data, t_locks *locks, t_bool val)
{
	pthread_mutex_lock(&locks->mtx_death);
	data->flag_death = val;
	pthread_mutex_unlock(&locks->mtx_death);
}

void	set_full_flag(t_shared *data, t_locks *locks, t_bool val)
{
	pthread_mutex_lock(&locks->mtx_full);
	data->flag_full = val;
	pthread_mutex_unlock(&locks->mtx_full);
}
