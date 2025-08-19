/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:06:41 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:31:46 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

// Table initialization
t_table		*init_table(char **argv, int argc);

// Philosopher initialization  
t_bool		init_philos(t_philo **philos, char **argv, int argc);
void		init_custom_data(t_custom *data, char **argv, int argc);
void		set_left_forks(t_philo *philos);
void		set_fork_priority(t_philo *philos);

// Locks initialization
t_bool		init_locks(t_locks **locks);

// Shared data initialization
t_bool		init_shared(t_shared **shared);
void		set_common_data(t_philo *philos, t_shared *shared, t_locks *locks);

#endif
