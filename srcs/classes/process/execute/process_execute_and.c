/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_and.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 18:09:02 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   and
**
** OPCODE
**
**   0x06
**
** 42 SUBJECT REFERENCE
**
**   and: Apply an & (bit-to-bit AND) over the first two arguments and store
**   the result in a registry, which is the third argument. Opcode 0x06.
**   Modifies the carry.
**
** EPITECH SUBJECT REFERENCE
**
**   p1 & p2 -> p3, the parameter 3 is always a register This operation
**   modifies the carry. and r2, %0,r3 stores r2 & 0 in r3.
**
** USAGE EXAMPLE
**
**   and	r6,%2147483648,r8
**
**   {"and", 3, {T_REG | T_DIR | T_IND,
**				 T_REG | T_IND | T_DIR,
**               T_REG},
**		6, 6,
**		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0}
*/

void		process_execute_and(t_process *self, int v[3], t_arg_type t[3])
{
	int		a;
	int		b;

	a = process_get(self, t[0], v[0]);
	b = process_get(self, t[1], v[1]);
	self->reg[v[2]] = a & b;
	self->carry = (self->reg[v[2]] == 0);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
		ft_printf("Process %4d | and %d %d r%d\n", self->id, a, b,
			v[2]);
}
