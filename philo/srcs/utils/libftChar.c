/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftChar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlu <eunlu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:46:16 by eunlu             #+#    #+#             */
/*   Updated: 2025/08/19 15:46:23 by eunlu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
