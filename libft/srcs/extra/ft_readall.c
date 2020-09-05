/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 20:53:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 20:53:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_readall(int fd, char *data, size_t size)
{
	size_t		used;
	ssize_t		n;

	used = 0;
	while (used < size)
	{
		n = read(fd, data + used, size - used);
		if (n <= 0)
			break ;
		used += n;
	}
	return (used == size);
}
