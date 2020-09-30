/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:39:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:30:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void			vm_start(t_vm *self)
{
	long		pc;
	t_player	*player;
	t_process	*process;

	pc = 0;
	vector_start(self->players);
	while (vector_next(self->players, (void **)&player))
	{
		vm_write(self, (void *)pc, player->data, player->size);
		process = process_create(self, player, pc);
		list_push_front(self->processes, process);
		pc += MEM_SIZE / self->players->count;
	}
}
