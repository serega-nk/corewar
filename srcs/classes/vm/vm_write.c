/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:24:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 19:38:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_write(t_vm *self, long pc, char *data, size_t size)
{
	size_t	index;
	size_t	norme;
	
	index = 0;
	while (index < size)
	{
		norme = (size_t)((MEM_SIZE + ((pc + index) % MEM_SIZE)) % MEM_SIZE);
		self->mem[norme] = data[index];
		index++;
	}
}
