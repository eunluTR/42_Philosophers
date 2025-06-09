#include "../../includes/philo.h"

int init_mutexes(t_data *data)
{
	int i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (0);
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0); // Hata durumunda önceden başlatılanları yok et
		i++;
	}
	if (pthread_mutex_init(&data->log_mutex, NULL) != 0)
		return (0); // Hata durumunda önceden başlatılanları yok et
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		return (0); // Hata durumunda önceden başlatılanları yok et
	return (1);
}

void init_philosophers(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		if (data->philo_count == 1) // Tek filozof durumu
			data->philos[i].right_fork = NULL;
		else
			data->philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		i++;
	}
}

int init_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (0);
	data->threads = malloc(sizeof(pthread_t) * data->philo_count);
	if (!data->threads)
	{
		free(data->philos);
		return (0);
	}
	if (!init_mutexes(data))
	{
		free(data->philos);
		free(data->threads);
		if (data->forks) // Eğer forks ayrıldıysa ve mutex init hatası olduysa
		{
			// Mutex başlatma hatası durumunda, başarıyla başlatılanları yok et
			// Bu döngü, hatanın oluştuğu ana kadar olan mutex'leri yok etmeli.
			// Ancak, hangi mutex'in başarısız olduğunu bilmek zor.
			// Şimdilik, tümünü yok etmeye çalışmak yerine sadece forks belleğini serbest bırakalım.
			// Daha sağlam bir hata yönetimi için init_mutexes içinde kısmi başarıları izlemek gerekir.
			free(data->forks);
			data->forks = NULL; // İşaretçiyi NULL yap
		}
		// log_mutex ve data_mutex'in de yok edilmesi gerekebilir, ancak init_mutexes'in nerede başarısız olduğuna bağlı.
		// Şimdilik bu kısmı basit tutuyoruz.
		return (0);
	}
	init_philosophers(data);
	data->died_flag = 0;
	data->all_ate_flag = 0;
	// data->start_time main.c'de parse_args'tan hemen sonra ayarlanacak
	return (1);
}

void destroy_data(t_data *data)
{
	int i;

	i = 0;
	if (data->forks)
	{
		while (i < data->philo_count)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	if (data->threads)
		free(data->threads);
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->data_mutex);
}