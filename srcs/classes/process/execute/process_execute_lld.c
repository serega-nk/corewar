/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lld.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 06:32:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

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
