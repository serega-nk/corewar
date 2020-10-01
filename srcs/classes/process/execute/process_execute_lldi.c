/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lldi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:57:15 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   lldi
**
** OPCODE
**
**   0x0e
**
** 42 SUBJECT REFERENCE
**
**   lldi: Opcode 0x0e. Same as ldi, but does not apply any modulo to the
**   addresses. It will however, modify the carry.
**
** EPITECH SUBJECT REFERENCE
**
**   Same as ldi, without the % IDX_MOD This operation modifies the carry.
**
** USAGE EXAMPLE
**
**   -
**
**   {"lldi", 3, {T_REG | T_DIR | T_IND,
**                T_DIR | T_REG,
**                T_REG},
**      14, 50,
**		"long load index", 1, 1}
*/

static int	process_lget_fix(t_process *self, t_arg_type type, int value)
{
	int		rel;

	if (type & T_DIR)
		rel = value;
	else if (type & T_IND)
		rel = process_lread(self, value % IDX_MOD);
	else
		rel = self->reg[value];
	return (rel);
}

void		process_execute_lldi(t_process *self, int v[3], t_arg_type t[3])
{
	int		rel0;
	int		rel1;

	rel0 = process_lget_fix(self, t[0], v[0]);
	rel1 = process_lget_fix(self, t[1], v[1]);
	self->reg[v[2]] = process_lread(self, rel0 + rel1);
	self->carry = (self->reg[v[2]] == 0);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("Process %4d | lldi %d %d r%d\n", self->id, rel0, rel1, v[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		rel0, rel1, rel0 + rel1, self->pc + rel0 + rel1);
	}
}
