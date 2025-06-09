#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// Ana veri yapıları ve fonksiyon prototipleri buraya eklenecek

typedef struct s_philo
{
	int			id;
	pthread_t	thread_id; // Her filozof için thread ID'si
	int			eat_count;
	long long	last_meal;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	struct s_data *data;
} t_philo;

typedef struct s_data
{
	int			philo_count;
	long long	time_to_die;
	long long	time_to_eat;
	long long	time_to_sleep;
	int			must_eat_count; // Opsiyonel argüman
	long long	start_time;
	int			died_flag;      // Bir filozofun ölüp ölmediğini belirtir
	int			all_ate_flag;   // Tüm filozofların yeterince yiyip yemediğini belirtir
	pthread_mutex_t	data_mutex; // died_flag ve all_ate_flag'ı korumak için
	pthread_mutex_t	log_mutex;  // print_status için mutex
	pthread_mutex_t	*forks;     // Çatal mutex'leri dizisi
	t_philo		*philos;            // Filozof yapısı dizisi
	pthread_t		*threads;         // Thread ID'leri dizisi (main.c'de kullanılacak)
} t_data;

// Fonksiyon prototipleri
int		init_data(t_data *data);
void	destroy_data(t_data *data);
long long	timestamp(void);
void	print_status(t_philo *philo, char *msg);

#endif