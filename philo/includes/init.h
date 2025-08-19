#ifndef INIT_H
# define INIT_H

# include "philo.h"

// Init module function prototypes
t_table		*init_table(char **argv, int argc);
t_bool		init_philos(t_philo **philos, char **argv, int argc);
void		init_custom_data(t_custom *data, char **argv, int argc);
void		set_left_forks(t_philo *philos);
void		set_fork_priority(t_philo *philos);

#endif
