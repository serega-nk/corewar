/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lfork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:56:21 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   lfork
**
** OPCODE
**
**   0x0f
**
** 42 SUBJECT REFERENCE
**
**   lfork: means long-fork, to be able to fork abut straw from a distance
**   of 15 meters, exactly like with its opcode. Same as a fork without
**   modulo in the address.
**
** EPITECH SUBJECT REFERENCE
**
**   Same as fork, without the % IDX_MOD This operation modifies the carry.
**
** USAGE EXAMPLE
**
**   lfork %:var1
**   lfork %2957
**
**   {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1}
*/

void	process_execute_lfork(t_process *self, int v[3])
{
	t_process	*clone;

	clone = process_clone(self, self->pc + v[0]);
	list_push_back(self->vm->fork_processes, clone);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("Process %4d | lfork %d (%d)\n",
			self->id, v[0], self->pc + v[0]);
	}
}
