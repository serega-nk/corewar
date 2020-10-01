/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_st.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:57:42 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   st
**
** OPCODE
**
**   0x03
**
** 42 SUBJECT REFERENCE
**
**   st: take a registry and a registry or an indirect and store the value of
**   the registry toward a second argument. Its opcode is 0x03. For example,
**   st r1, 42 store the value of r1 at the address (PC + (42 % IDX_MOD))
**
** EPITECH SUBJECT REFERENCE
**
**   This instruction takes 2 parameters. It stores (REG_SIZE bytes) the value
**   of the first argument (always a register) in the second. st r4,34 stores
**   the value of r4 at the address (PC + (34 % IDX_MOD)) st r3,r8 copies r3
**   in r8
**
** USAGE EXAMPLE
**
**   st r5,r2
**   st r1, :boucle+1
**
**   {"st", 2, {T_REG,
**              T_IND | T_REG},
**    3, 5, "store", 1, 0}
*/

void	process_execute_st(t_process *self, int v[3], t_arg_type t[3])
{
	if (t[1] & T_IND)
		process_write(self, v[1], self->reg[v[0]]);
	else
		self->reg[v[1]] = self->reg[v[0]];
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
		ft_printf("Process %4d | st r%d %d\n", self->id, v[0], v[1]);
}
