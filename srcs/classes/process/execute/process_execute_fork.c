/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:32:16 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_fork(t_process *self, int v[3])
{
	t_process	*clone;

	clone = process_clone(self, v[0] % IDX_MOD);
	list_push_back(self->vm->fork_processes, clone);
}
