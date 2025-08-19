#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>


typedef uint64_t					t_ms;
typedef pthread_mutex_t			t_mutex;

typedef enum e_bool { FALSE, TRUE } t_bool;

typedef enum e_status
{
	ST_PICKING_UP_FORK,
	ST_EATING,
	ST_SLEEPING,
	ST_THINKING,
	ST_DEAD
} t_status;

# define SUCCESS 0
# define MAX_INT 2147483647
# define NEWLINE "\n"

# define MSG_FORK   "has taken a fork"
# define MSG_EAT    "is eating"
# define MSG_SLEEP  "is sleeping"
# define MSG_THINK  "is thinking"
# define MSG_DEAD   "died"

# define ERR_BAR "==============================================="
# define ERR_DEFAULT "Error"
# define ERR_INV_ARGC "Invalid number of argument!"
# define ERR_INV_ARGV "Invalid argument value!"
# define ERR_ALLOC "Allocation Failed!"
# define ERR_MTX_INIT "Mutex initialization failed!"
# define ERR_MTX_DESTROY "Mutex destroy failed!"
# define ERR_PTHREAD_CREATE "Pthread create failed!"
# define ERR_GETTIMEOFDAY "gettimeofday() failed!"


typedef struct s_locks
{
	t_mutex		mtx_print;
	t_mutex		mtx_death;
	t_mutex		mtx_error;
	t_mutex		mtx_full;
	t_mutex		mtx_meal;
	t_bool		init_print;
	t_bool		init_death;
	t_bool		init_error;
	t_bool		init_full;
	t_bool		init_meal;
} t_locks;

typedef struct s_shared
{
	t_bool		flag_error;
	t_bool		flag_death;
	t_bool		flag_full;
} t_shared;

typedef struct s_custom
{
	int			eat_limit;
	int			eat_count;
	size_t		philo_count;
	t_ms		lifetime;
	t_ms		meal_time;
	t_ms		sleep_time;
	t_ms		last_meal_time;
	t_ms		start_ts;
} t_custom;

struct s_philo;

typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_bool		is_full;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		*first_fork;
	t_mutex		*last_fork;
	t_custom	data;
	t_shared	*shared;
	t_locks		*locks;
} t_philo;

typedef struct s_table
{
	t_philo		*philos;
	pthread_t	monitor;
	t_locks		*locks;
	t_shared	*shared;
	t_custom	data;
} t_table;


t_table		*init_table(char **argv, int argc);
t_bool		init_philos(t_philo **philos, char **argv, int argc);
void		init_custom_data(t_custom *data, char **argv, int argc);
void		set_left_forks(t_philo *philos);
void		set_fork_priority(t_philo *philos);
t_table		*init(char **argv, int argc);

t_bool		init_simulation(t_table *table);
void		*monitor(void *arg);
void		start_routine(t_philo *philo);
t_bool		eating(t_philo *philo);
t_bool		start_simulation(t_table *table);

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

void		set_error_flag(t_shared *data, t_locks *locks, t_bool val);
void		set_death_flag(t_shared *data, t_locks *locks, t_bool val);
void		set_full_flag(t_shared *data, t_locks *locks, t_bool val);
t_bool		get_error_flag(t_shared *data, t_locks *locks);
t_bool		get_death_flag(t_shared *data, t_locks *locks);
t_bool		get_full_flag(t_shared *data, t_locks *locks);
void		lock_the_mutex(t_mutex *lock);
void		unlock_the_mutex(t_mutex *lock);

#endif
