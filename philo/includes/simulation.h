#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"

// Simulation module function prototypes
t_bool		init_simulation(t_table *table);
void		*monitor(void *arg);
void		start_routine(t_philo *philo);
t_bool		eating(t_philo *philo);

#endif
