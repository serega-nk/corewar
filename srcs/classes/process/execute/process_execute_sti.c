/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_sti.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:58:04 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   sti
**
** OPCODE
**
**   0x0b
**
** 42 SUBJECT REFERENCE
**
**   sti: Opcode 11. Take a registry, and two indexes (potentially
**   registries) add the two indexes, and use this result as an address
**   where the value of the first parameter will be copied.
**
** EPITECH SUBJECT REFERENCE
**
**   sti r2,%4,%5 sti copies REG_SIZE bytes of r2 at address (4 + 5)
**   Parameters 2 and 3 are indexes. If they are, in fact, registers,
**   we’ll use their contents as indexes.
**
** USAGE EXAMPLE
**
**   sti r7,%-250,r6
**   sti r10, r11, r13
**
**   {"sti", 3, {T_REG,
**               T_REG | T_DIR | T_IND,
**               T_DIR | T_REG},
**      11, 25,
**		"store index", 1, 1}
*/

void	process_execute_sti(t_process *self, int v[3], t_arg_type t[3])
{
	int		data;
	int		rel1;
	int		rel2;

	data = process_get(self, t[0], v[0]);
	rel1 = process_get(self, t[1], v[1]);
	rel2 = process_get(self, t[2], v[2]);
	process_write(self, rel1 + rel2, data);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("Process %4d | sti r%d %d %d\n", self->id, v[0], rel1, rel2);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
			rel1, rel2, rel1 + rel2, self->pc + (rel1 + rel2) % IDX_MOD);
	}
}
