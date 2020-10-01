/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:55:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 19:11:26 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_bool		is_dead_process(t_vm *self, t_process *process)
{
	return (self->cycles_to_die <= 0 ||
		self->cycles_num - process->last_live >= self->cycles_to_die);
}

static void			stop_processes(t_vm *self)
{
	t_list_iter		*iter;
	t_process		*process;

	iter = list_iter_create(self->processes);
	while (list_iter_next(iter, (void **)&process))
	{
		if (is_dead_process(self, process))
		{
			if (self->verbosity & VERBOSITY_DEATHS)
			{
				ft_printf("Process %d hasn't lived for %d cycles (Cycles_to_die %d)\n",
				process->id, self->cycles_num - process->last_live, self->cycles_to_die);
			}
			list_iter_remove(iter, &process_destroy);
		}
	}
	list_iter_destroy(&iter);
}

void				vm_check(t_vm *self)
{
	if (self->cycles_to_die == self->cycles_after_check ||
		self->cycles_to_die <= 0)
	{
		self->checks_num++;
		stop_processes(self);
		if (self->checks_num >= MAX_CHECKS || self->lives_num >= NBR_LIVE)
		{
			self->cycles_to_die -= CYCLE_DELTA;
			self->checks_num = 0;
		}
		self->lives_num = 0;
		self->cycles_after_check = 0;
	}
}
