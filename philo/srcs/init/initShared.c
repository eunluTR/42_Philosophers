/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initShared.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:10:41 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:31:46 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	init_shared(t_shared **shared)
{
	*shared = (t_shared *)ft_calloc(1, sizeof(t_shared));
	if (!*shared)
		return (display_err_msg(ERR_ALLOC));
	return (TRUE);
}

void	set_common_data(t_philo *philos, t_shared *shared, t_locks *locks)
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
