/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_or.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:43:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 18:18:25 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   or
**
** OPCODE
**
**   0x07
**
** 42 SUBJECT REFERENCE
**
**   or: This operation is an bit-to-bit OR, in the same spirit and principle
**   of and, its opcode is obviously 7
**
** EPITECH SUBJECT REFERENCE
**
**   Same as and but with an or (| in C)
**
** USAGE EXAMPLE
**
**   or r2, %16, r2
**   or r1, r1, r7
**   or r12, r12, r12
**
**   {"or", 3, {T_REG | T_IND | T_DIR,
**              T_REG | T_IND | T_DIR,
**              T_REG},
**    7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0}
*/

void		process_execute_or(t_process *self, int v[3], t_arg_type t[3])
{
	int		a;
	int		b;

	a = process_get(self, t[0], v[0]);
	b = process_get(self, t[1], v[1]);
	self->reg[v[2]] = a | b;
	self->carry = (self->reg[v[2]] == 0);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
		ft_printf("Process %4d | or %d %d r%d\n", self->id, a, b, v[2]);
}
