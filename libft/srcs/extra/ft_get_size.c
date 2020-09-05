/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 20:54:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 20:54:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_size(int fd)
{
	off_t		curr;
	size_t		size;

	curr = lseek(fd, 0, SEEK_CUR);
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, curr, SEEK_SET);
	return (size);
}
