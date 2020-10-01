/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:55:47 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   ld
**
** OPCODE
**
**   0x02
**
** 42 SUBJECT REFERENCE
**
**   ld: Take a random argument and a registry. Load the value of the first
**   argument in the registry. Its opcode is 10 in binary and it will change
**   the carry.
**
** EPITECH SUBJECT REFERENCE
**
**   This instruction takes 2 parameters, the 2nd of which has to be a register
**   (not the PC) It loads the value of the first parameter in the register.
**   This operation modifies the carry. ld 34,r3 loads the REG_SIZE bytes from
**   address (PC + (34 % IDX_MOD)) in register r3.
**
** USAGE EXAMPLE
**
**   ld $4, r5
**            (load 4 in r5)
**   ld %:label, r7
**            (load label in r7)
**
**   {"ld", 2, {T_DIR | T_IND,
**              T_REG},
**    2, 5, "load", 1, 0}
*/

void		process_execute_ld(t_process *self, int v[3], t_arg_type t[3])
{
	self->reg[v[1]] = process_get(self, t[0], v[0]);
	self->carry = (self->reg[v[1]] == 0);
}
