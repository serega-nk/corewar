/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:00:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 18:20:14 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   sub
**
** OPCODE
**
**   0x05
**
** 42 SUBJECT REFERENCE
**
**   sub: Same as add, but with the opcode est 0b101, and uses a substraction.
**
** EPITECH SUBJECT REFERENCE
**
**   Same effect as add, but with a substraction
**
** USAGE EXAMPLE
**
**   sub r10,r11,r10
**
**   {"sub", 3, {T_REG,
**               T_REG,
**               T_REG},
**    5, 10, "soustraction", 1, 0}
*/

void	process_execute_sub(t_process *self, int v[3])
{
	self->reg[v[2]] = self->reg[v[0]] - self->reg[v[1]];
	self->carry = (self->reg[v[2]] == 0);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
		ft_printf("Process %4d | sub r%d r%d r%d\n", self->id, v[0], v[1],
		v[2]);
}
