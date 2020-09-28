/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:03:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 19:06:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static void			execute_processes(t_vm *self)
{
	t_list_iter		*iter;
	t_process		*process;

	iter = list_iter_create(self->processes);
	while (list_iter_next(iter, (void **)&process))
	{
		process_execute(process);
	}
	list_iter_destroy(&iter);
}

static void			add_new_processes(t_vm *self)
{
	t_list_iter		*iter;
	t_process		*process;

	iter = list_iter_create(self->new_processes);
	while (list_iter_next(iter, (void **)&process))
	{
		list_push_front(self->processes, process);
		list_iter_remove(iter, NULL);
	}
	list_iter_destroy(&iter);
}

void				vm_next(t_vm *self)
{
	self->cycles_num++;
	self->cycles_after_check++;
	execute_processes(self);
	add_new_processes(self);
}
