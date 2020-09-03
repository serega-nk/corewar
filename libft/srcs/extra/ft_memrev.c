/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 00:28:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/04 00:30:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memrev(void *addr, size_t len)
{
	unsigned char	*ptr;
	unsigned char	temp;
	size_t			index;	

	if (addr && len)
	{
		ptr = (unsigned char *)addr;
		index = 0;
		while (index < len / 2)
		{
			temp = ptr[len - index - 1];
			ptr[len - index - 1] = ptr[index];
			ptr[index] = temp;
			index++;
		}
	}
}
