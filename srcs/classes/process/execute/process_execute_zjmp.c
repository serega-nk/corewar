/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_zjmp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:43:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 18:25:07 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   zjmp
**
** OPCODE
**
**   0x09
**
** 42 SUBJECT REFERENCE
**
**   zjmp: there’s never been, isn’t and will never be an argument’s coding
**   byte behind this operation where the opcode is 9. It will take an index
**   and jump to this address if the carry is 1.
**
** EPITECH SUBJECT REFERENCE
**
**   This instruction is not followed by any parameter encoding byte. It always
**   takes an index (IND_SIZE) and makes a jump at this index if the carry is
**   set to 1. If the carry is null, zjmp does nothing but consumes the same
**   amount of time. zjmp %23 does : If carry == 1, store (PC + (23 % IDX_MOD))
**   in the PC.
**
** USAGE EXAMPLE
**
**   zjmp %0
**   zjmp %:cont
**
**   {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1}
*/

void	process_execute_zjmp(t_process *self, int v[3])
{
	if (self->carry)
	{
		self->step = v[0] % IDX_MOD;
		if (self->vm->verbosity & VERBOSITY_OPERATIONS)
			ft_printf("P %4d | zjmp %d %s\n", self->id, v[0],
			self->carry ? "OK" : "FAILED");
	}
}
