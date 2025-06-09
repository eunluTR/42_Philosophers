#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

int is_number(const char *str);
int parse_args(int argc, char **argv, t_data *data);
void assign_philosophers(t_data *data);
long long timestamp(void);
void print_status(t_philo *philo, char *msg);

#endif
