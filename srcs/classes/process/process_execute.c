/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:02:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:25:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute(t_process *self)
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
		if (process_arguments(self) == FALSE)
		{
			process_move(self);
			return ;
		}
		process_move(self);
	}
}
