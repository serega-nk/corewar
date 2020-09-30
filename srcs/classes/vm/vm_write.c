/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:24:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:29:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_write(t_vm *self, void *addr, void *data, size_t size)
{
	size_t			index;
	size_t			norme;
	unsigned char	*ptr;
	
	ptr = (unsigned char *)data;
	index = 0;
	while (index < size)
	{
		norme = (size_t)((MEM_SIZE + (((long)addr + index) % MEM_SIZE)) % MEM_SIZE);
		self->mem[norme] = ptr[index];
		index++;
	}
}
