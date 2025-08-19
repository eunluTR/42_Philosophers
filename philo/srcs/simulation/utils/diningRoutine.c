#include "philo.h"

static t_bool	sleeping(t_philo *ph)
{
	if (!display_status(ph, ST_SLEEPING))
		return (FALSE);
	elapse_time(ph->shared, ph->locks, ph->data.sleep_time);
	return (TRUE);
}

static t_bool	thinking(t_philo *ph)
{
	usleep(200);
	return (display_status(ph, ST_THINKING));
}

void	start_routine(t_philo *ph)
{
	while (TRUE)
	{
		if (!eating(ph))
			return ;
		if (!sleeping(ph))
			return ;
		if (!thinking(ph))
			return ;
	}
}
