/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 20:51:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 20:52:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_writeall(int fd, char *data, size_t size)
{
	size_t		used;
	ssize_t		n;

	used = 0;
	while (used < size)
	{
		n = write(fd, data + used, size - used);
		if (n <= 0)
			break ;
		used += n;
	}
	return (used == size);
}
