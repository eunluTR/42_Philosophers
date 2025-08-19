/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:10:18 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:10:24 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (!(argc == 5 || argc == 6))
		return (display_err_msg(ERR_INV_ARGC));
	if (!check_args(argc, argv))
		return (display_err_msg(ERR_INV_ARGV));
	table = init_table(argv, argc);
	if (!table)
		return (1);
	if (!init_simulation(table))
	{
		free_table(table);
		return (1);
	}
	if (table->shared->flag_error)
	{
		free_table(table);
		return (1);
	}
	free_table(table);
	return (0);
}
