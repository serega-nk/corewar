/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ldi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:22:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 19:18:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   ldi
**
** OPCODE
**
**   0x0a
**
** 42 SUBJECT REFERENCE
**
**   ldi: ldi, ldi, as per the name, does not imply to go swimming in chestnut
**   cream, even if its code is 0x0a. Instead, it will use 2 indexes and 1
**   registry, adding the first two, treating that like an address, reading
**   a value of a registry’s size and putting it on the third.
**
** EPITECH SUBJECT REFERENCE
**
**   This operation modifies the carry. ldi 3,%4,r1 reads IND_SIZE bytes at
**   address: (PC + (3 % IDX_MOD)), adds 4 to this value. We will name this
**   sum S. Read REG_SIZE bytes at address (PC + (S % IDX_MOD)), which are
**   copied to r1. Parameters 1 and 2 are indexes.
**
** USAGE EXAMPLE
**
**   ldi %:copie, %3, r2
**   ldi %0, %:bomb_b, r8
**
**   {"ldi", 3, {T_REG | T_DIR | T_IND,
**               T_DIR | T_REG,
**               T_REG},
**      10, 25,
**      "load index", 1, 1}
*/

void		process_execute_ldi(t_process *self, int v[3], t_arg_type t[3])
{
	int		rel0;
	int		rel1;

	rel0 = process_get(self, t[0], v[0]);
	rel1 = process_get(self, t[1], v[1]);
	self->reg[v[2]] = process_read(self, rel0 + rel1);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("P %4d | ldi %d %d r%d\n", self->id, rel0, rel1, v[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
			rel0, rel1, rel0 + rel1, self->pc + (rel0 + rel1) % IDX_MOD);
	}
}
