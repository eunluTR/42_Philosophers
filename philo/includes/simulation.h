/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:07:15 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:07:16 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

t_bool		init_simulation(t_table *table);
void		*monitor(void *arg);
void		start_routine(t_philo *philo);
t_bool		eating(t_philo *philo);

#endif
