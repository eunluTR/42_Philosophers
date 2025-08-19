#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			total;
	size_t			i;

	total = count * size;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
		ptr[i++] = 0;
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_atoui(const char *str)
{
	int		sign;
	size_t	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_putendl(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, NEWLINE, 1);
}

void	ft_putstr(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}


t_bool	ft_isspace(char c)
{
	char	*sp;
	int		i;

	sp = " \t\n\v\f\r";
	i = 0;
	while (sp[i])
	{
		if (c == sp[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}


t_bool	ft_isdigit(char c)
{
	return ((int)c >= 48 && (int)c <= 57);
}
