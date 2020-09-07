/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:35:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 04:16:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	instruction_calc_size(t_instruction *self)
{
	t_argument	*argument;

	self->size = 1;
	if (self->op->use_types)
		self->size += 1;
	vector_start(self->arguments);
	while (vector_next(self->arguments, (void **)&argument))
	{
		if (argument->arg_type & T_REG)
			argument->size = REG_LENGTH;
		else if (argument->arg_type & T_DIR)
			argument->size = (self->op->dir_ind ? IND_LENGTH : DIR_LENGTH);
		else if (argument->arg_type & T_IND)
			argument->size = IND_LENGTH;
		self->size += argument->size;
	}
	return (self->size);
}
