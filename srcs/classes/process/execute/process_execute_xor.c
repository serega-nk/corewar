/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_xor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:43:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:58:41 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   xor
**
** OPCODE
**
**   0x08
**
** 42 SUBJECT REFERENCE
**
**   xor: Acts like and with an exclusive OR. As you will have guessed,
**   its opcode in octal is 10.
**
** EPITECH SUBJECT REFERENCE
**
**   Same as and but with an xor (^ in C)
**
** USAGE EXAMPLE
**
**   xor r3, %-430, r15
**   xor r2, r2, r2
**   xor r1, r1, r5
**
**   {"xor", 3, {T_REG | T_IND | T_DIR,
**               T_REG | T_IND | T_DIR,
**               T_REG},
**      8, 6,
**		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0}
*/

void		process_execute_xor(t_process *self, int v[3], t_arg_type t[3])
{
	int		a;
	int		b;

	a = process_get(self, t[0], v[0]);
	b = process_get(self, t[1], v[1]);
	self->reg[v[2]] = a ^ b;
	self->carry = (self->reg[v[2]] == 0);
}
