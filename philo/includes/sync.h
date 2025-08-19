/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:07:20 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:07:21 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNC_H
# define SYNC_H

# include "philo.h"

void		set_error_flag(t_shared *data, t_locks *locks, t_bool val);
void		set_death_flag(t_shared *data, t_locks *locks, t_bool val);
void		set_full_flag(t_shared *data, t_locks *locks, t_bool val);
t_bool		get_error_flag(t_shared *data, t_locks *locks);
t_bool		get_death_flag(t_shared *data, t_locks *locks);
t_bool		get_full_flag(t_shared *data, t_locks *locks);
void		lock_the_mutex(t_mutex *lock);
void		unlock_the_mutex(t_mutex *lock);

#endif
