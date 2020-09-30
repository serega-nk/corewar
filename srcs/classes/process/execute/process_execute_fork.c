/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 01:47:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_fork(t_process *self, int v[3])
{
	t_process	*clone;

	clone = process_clone(self, self->pc + v[0] % IDX_MOD);
	list_push_back(self->vm->fork_processes, clone);
}
