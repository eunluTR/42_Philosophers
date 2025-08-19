#include "philo.h"

static void	str_rtrim(char *str);
static t_bool	check_limit(char *arg);
static t_bool	check_validation(char *arg);

static t_bool	is_positive_number(char *arg)
{
	int i;

	i = 0;
	while (arg[i] && ft_isspace(arg[i]))
		i++;
	if (arg[i] == '+')
		i++;
	if (!arg[i])
		return (FALSE);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_args(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		str_rtrim(argv[i]);
		if (!check_validation(argv[i]) || !check_limit(argv[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_validation(char *arg)
{
	if (!arg)
		return (FALSE);
	return (is_positive_number(arg));
}

static t_bool	check_limit(char *arg)
{
	size_t	val;
	int		i;

	i = 0;
	while (ft_isspace(arg[i]))
		i++;
	val = ft_atoui(arg + i);
	if (val > MAX_INT || val <= 0)
		return (FALSE);
	return (TRUE);
}

static void	str_rtrim(char *str)
{
	int i;

	i = (int)ft_strlen(str) - 1;
	while (i >= 0 && ft_isspace(str[i]))
	{
		str[i] = '\0';
		i--;
	}
}
