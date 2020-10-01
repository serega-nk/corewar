/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lld.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:57:01 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   lld
**
** OPCODE
**
**   0x0d
**
** 42 SUBJECT REFERENCE
**
**   lld: Means long-load, so it’s opcode is obviously 13. It the same as ld,
**   but without % IDX_MOD. Modify the carry.
**
** EPITECH SUBJECT REFERENCE
**
**   Same as ld, but without the % IDX_MOD This operation modifies the carry.
**
** USAGE EXAMPLE
**
**   -
**
**   {"lld", 2, {T_DIR | T_IND,
**               T_REG},
**    13, 10, "long load", 1, 0}
*/

static int		process_lread_fix(t_process *self, long rel)
{
	short		value;

	vm_read(self->vm, self->pc + rel, &value, sizeof(value));
	ft_memrev(&value, sizeof(value));
	return (value);
}

static int		process_lget_fix(t_process *self, t_arg_type type, int value)
{
	int		rel;

	if (type & T_DIR)
		rel = value;
	else if (type & T_IND)
		rel = process_lread_fix(self, value);
	else
		rel = self->reg[value];
	return (rel);
}

void			process_execute_lld(t_process *self, int v[3], t_arg_type t[3])
{
	self->reg[v[1]] = process_lget_fix(self, t[0], v[0]);
	self->carry = (self->reg[v[1]] == 0);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("Process %4d | lld %d r%d\n", self->id, t[0], v[0]);
	}
}
