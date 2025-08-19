/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncLock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:31:31 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:31:31 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	lock_the_mutex(t_mutex *lock)
{
	pthread_mutex_lock(lock);
}

void	unlock_the_mutex(t_mutex *lock)
{
	pthread_mutex_unlock(lock);
}
