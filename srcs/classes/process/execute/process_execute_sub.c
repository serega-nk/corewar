/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:00:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:58:25 by wzei             ###   ########.fr       */
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
}
