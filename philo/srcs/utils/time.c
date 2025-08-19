/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:48:13 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:48:37 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_bool	set_err_and_print(t_shared *data, t_locks *locks)
{
	lock_the_mutex(&locks->mtx_print);
	display_err_msg(ERR_GETTIMEOFDAY);
	set_error_flag(data, locks, TRUE);
	unlock_the_mutex(&locks->mtx_print);
	return (FALSE);
}

t_ms	get_timestamp(t_shared *data, t_locks *locks)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != SUCCESS)
	{
		set_err_and_print(data, locks);
		return (0);
	}
	return ((t_ms)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	elapse_time(t_shared *data, t_locks *locks, t_ms duration)
{
	t_ms	start;
	t_ms	now;

	start = get_timestamp(data, locks);
	while (TRUE)
	{
		now = get_timestamp(data, locks);
		if ((now - start) >= duration)
			break ;
		usleep(100);
	}
}
