/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ldi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:22:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:42:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_ldi(t_process *self)
{
	int		a;
	int		b;
	long	rel;

	if (self->arg_types[0] & T_DIR)
		a = self->args[0];
	else if (self->arg_types[0] & T_IND)
		a = vm_read_int(self->vm, self->pc + (self->args[0] % IDX_MOD));
	else
		a = self->reg[self->args[0]];
	if (self->arg_types[1] & T_DIR)
		b = self->args[1];
	else
		b = self->reg[self->args[1]];	
	self->reg[self->args[2]] = vm_read_int(self->vm,
		self->pc + ((a + b) % IDX_MOD));
}
