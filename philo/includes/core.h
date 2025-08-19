#ifndef CORE_H
# define CORE_H

# include "philo.h"

// Core module function prototypes
t_bool		check_args(int argc, char **argv);
void		free_table(t_table *table);

void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(char *str);
size_t		ft_atoui(const char *str);
t_bool		ft_isspace(char c);
t_bool		ft_isdigit(char c);
void		ft_putstr(char *str, int fd);
void		ft_putendl(char *str, int fd);

t_ms		get_timestamp(t_shared *data, t_locks *locks);
void		elapse_time(t_shared *data, t_locks *locks, t_ms duration);
t_bool		display_status(t_philo *philo, t_status status);
t_bool		display_err_msg(char *msg);

#endif
