/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:55:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 18:53:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_bool		is_dead(t_vm *self, t_process *process)
{
	return (self->cycles_to_die <= 0 ||
		self->cycles_num - process->last_live >= self->cycles_to_die);
}

static void 		delete_died_process(t_vm *self)
{
	t_list_iter		*iter;
	t_process		*process;

	iter = list_iter_create(self->processes);
	while (list_iter_next(iter, (void **)&process))
	{
		if (is_dead(self, process))
			list_iter_remove(iter, &process_destroy);
	}
	list_iter_destroy(&iter);
}

static void 		reset_lives_num(t_vm *self)
{
	t_player		*player;
	
	self->lives_num = 0;	
	vector_start(self->players);
	while (vector_next(self->players, (void **)&player))
	{
		player->lives_num = 0;
	}
}

void				vm_check(t_vm *self)
{
	if (self->cycles_to_die == self->cycles_after_check ||
		self->cycles_to_die <= 0)
	{
		self->checks_num++;
		delete_died_process(self);
		if (self->checks_num >= MAX_CHECKS || self->lives_num >= NBR_LIVE)
		{
			self->cycles_to_die -= CYCLE_DELTA;
			self->checks_num = 0;
		}
		reset_lives_num(self);
		self->cycles_after_check = 0;
	}
}
