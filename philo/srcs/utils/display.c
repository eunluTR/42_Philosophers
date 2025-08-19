/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:47:23 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:48:08 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static const char	*get_msg(t_status st)
{
	if (st == ST_EATING)
		return (MSG_EAT);
	if (st == ST_SLEEPING)
		return (MSG_SLEEP);
	if (st == ST_THINKING)
		return (MSG_THINK);
	if (st == ST_DEAD)
		return (MSG_DEAD);
	if (st == ST_PICKING_UP_FORK)
		return (MSG_FORK);
	return ("unknown");
}

static void	print_line(t_philo *ph, t_status st, t_ms now)
{
	printf("%lu %d %s\n", now - ph->data.start_ts, ph->id, get_msg(st));
}

t_bool	display_err_msg(char *msg)
{
	ft_putendl(ERR_DEFAULT, STDERR_FILENO);
	ft_putendl(ERR_BAR, STDERR_FILENO);
	if (msg)
		ft_putendl(msg, STDERR_FILENO);
	ft_putendl(ERR_BAR, STDERR_FILENO);
	return (FALSE);
}

t_bool	display_status(t_philo *ph, t_status st)
{
	t_ms	now;

	lock_the_mutex(&ph->locks->mtx_print);
	now = get_timestamp(ph->shared, ph->locks);
	if (get_error_flag(ph->shared, ph->locks)
		|| get_death_flag(ph->shared, ph->locks)
		|| get_full_flag(ph->shared, ph->locks))
	{
		unlock_the_mutex(&ph->locks->mtx_print);
		return (FALSE);
	}
	if (st == ST_DEAD)
		set_death_flag(ph->shared, ph->locks, TRUE);
	print_line(ph, st, now);
	unlock_the_mutex(&ph->locks->mtx_print);
	return (TRUE);
}
