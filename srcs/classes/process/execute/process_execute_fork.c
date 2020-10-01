/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_fork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:53:54 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   fork
**
** OPCODE
**
**   0x0c
**
** 42 SUBJECT REFERENCE
**
**   fork: there is no argument’s coding byte, take an index, opcode 0x0c.
**   Create a new process that will inherit the different states of its father,
**   except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).
**
** EPITECH SUBJECT REFERENCE
**
**   This instruction is not followed by a parameter encoding byte.
**   It always takes an index and creates a new program, which is executed
**   from address : (PC + (first parameter % IDX_MOD)). Fork %34 creates a new
**   program. The new program inherits all of its father’s states.
**
** USAGE EXAMPLE
**
**   fork %:start
**   fork %42
**
**   {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1}
*/

void	process_execute_fork(t_process *self, int v[3])
{
	t_process	*clone;

	clone = process_clone(self, self->pc + v[0] % IDX_MOD);
	list_push_back(self->vm->fork_processes, clone);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("Process %4d | fork %d (%d)\n", self->id, v[0],
			self->pc + v[0] % IDX_MOD);
	}
}
