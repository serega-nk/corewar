/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:35:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/04 00:13:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	instruction_calc_size(t_instruction *self)
{
	t_argument	*argument;

	self->size = 1;
	if (self->op->use_arg_type)
		self->size += 1;
	vector_start(self->arguments);
	while (vector_next(self->arguments, (void **)&argument))
	{
		if (argument->arg_type & T_REG)
			self->size += REG_SIZE;
		else if (argument->arg_type & T_DIR)
			self->size += DIR_SIZE;
		else if (argument->arg_type & T_IND)
			self->size += IND_SIZE;
	}
	return (self->size);
}
