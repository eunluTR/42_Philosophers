#include "philo.h"

int	main(int argc, char **argv)
{
	t_table *table;

	if (!(argc == 5 || argc == 6))
		return (display_err_msg(ERR_INV_ARGC));
	if (!check_args(argc, argv))
		return (display_err_msg(ERR_INV_ARGV));
	table = init(argv, argc);
	if (!table)
		return (1);
	if (!start_simulation(table))
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
