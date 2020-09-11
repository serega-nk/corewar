/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 23:26:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:59:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *addr, size_t size)
{
	char	*ptr;
	size_t	index;
	char	temp;

	ptr = (char *)addr;
	index = 0;
	while (index < size / 2)
	{
		temp = ptr[index];
		ptr[index] = ptr[size - index - 1];
		ptr[size - index - 1] = temp;
		index++;
	}
}
