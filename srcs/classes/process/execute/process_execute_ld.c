/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:27:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		process_execute_ld(t_process *self)
{
	int		val;
	long	rel;

	if (self->arg_types[0] & T_DIR)
	{
		val = self->args[0];
	}
	else
	{
		rel = self->args[0] % IDX_MOD;
		val = vm_read_int(self->vm, self->pc + rel);
	}
	self->reg[self->args[1]] = val;
	self->carry = (val == 0);
}
