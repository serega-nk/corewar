/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:09:37 by wzei              #+#    #+#             */
/*   Updated: 2020/09/30 11:24:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_loop(t_vm *self)
{
	while (TRUE)
	{
		if (self->cycles_num == self->nbr_cycles)
		{
			vm_dump(self);
			break ;
		}
		vm_next(self);
		vm_check(self);
		if (self->processes->count == 0)
		{
			vm_final(self);
			break ;
		}
	}
}
