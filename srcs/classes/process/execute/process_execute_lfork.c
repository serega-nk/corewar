/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lfork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 05:23:11 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_lfork(t_process *self, int v[3])
{
	t_process	*clone;

	clone = process_clone(self, self->pc + v[0]);
	list_push_back(self->vm->fork_processes, clone);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
		ft_printf("Process %4d | lfork %d (%d)\n", self->id, v[0], self->pc + v[0]);
}
