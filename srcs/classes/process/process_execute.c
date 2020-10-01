/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:02:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 06:29:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static void		(*g_funcs[])() = {
	NULL,
	&process_execute_live,
	&process_execute_ld,
	&process_execute_st,
	&process_execute_add,
	&process_execute_sub,
	&process_execute_and,
	&process_execute_or,
	&process_execute_xor,
	&process_execute_zjmp,
	&process_execute_ldi,
	&process_execute_sti,
	&process_execute_fork,
	&process_execute_lld,
	&process_execute_lldi,
	&process_execute_lfork,
	&process_execute_aff
};

void			process_execute(t_process *self)
{
	if (self->cycles_wait == 0)
	{
		if (process_opcode(self) == FALSE)
		{
			process_move(self);
			return ;
		}
		self->cycles_wait = self->op->cycles_wait;
	}
	if (self->cycles_wait > 0)
		self->cycles_wait--;
	if (self->cycles_wait == 0)
	{
		if (process_arg_types(self) &&
			process_arguments(self) &&
			process_validate(self))
		{
			(*g_funcs[(size_t)self->op->code])(self, 
				self->args, self->arg_types);
		}
		process_move(self);
	}
}
