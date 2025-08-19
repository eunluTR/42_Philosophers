/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initLocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:10:41 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:31:46 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_bool	init_mutex(pthread_mutex_t *mtx, t_bool *flag)
{
	if (pthread_mutex_init(mtx, NULL) != SUCCESS)
		return (FALSE);
	*flag = TRUE;
	return (TRUE);
}

t_bool	init_locks(t_locks **locks)
{
	t_locks	*tmp;

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
