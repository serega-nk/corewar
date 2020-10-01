/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:52:08 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   add
**
** OPCODE
**
**   0x04
**
** 42 SUBJECT REFERENCE
**
**   add: Opcode 4. Take three registries, add the first two, and place the
**   result in the third, right before modifying the carry.
**
** EPITECH SUBJECT REFERENCE
**
**   This instruction takes 3 registers as parameter, adds the contents of
**   the 2 first and stores the result in the third. This operation modifies
**   the carry. add r2,r3,r5 adds r2 and r3 and stores the result in r5
**
** USAGE EXAMPLE
**
**   add r2, r3, r2
**   add r2, r3, r2
**
**   {"add", 3, {T_REG,
**               T_REG,
**               T_REG},
**    4, 10, "addition", 1, 0}
*/

void	process_execute_add(t_process *self, int v[3])
{
	self->reg[v[2]] = self->reg[v[0]] + self->reg[v[1]];
	self->carry = (self->reg[v[2]] == 0);
	if (TRUE)
	{
		
	}
}
