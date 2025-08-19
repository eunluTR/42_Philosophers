/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftString.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:46:42 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:46:45 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

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
