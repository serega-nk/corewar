/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 05:50:28 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_fork(t_process *self, int v[3])
{
	t_process	*clone;

	clone = process_clone(self, self->pc + v[0] % IDX_MOD);
	list_push_back(self->vm->fork_processes, clone);
		if (self->vm->verbosity & VERBOSITY_OPERATIONS)
			ft_printf("Process %4d | fork %d (%d)\n", self->id, v[0],
				self->pc + v[0] % IDX_MOD);
}
