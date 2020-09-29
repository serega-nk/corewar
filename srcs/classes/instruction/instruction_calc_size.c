/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:35:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:40:10 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

size_t			instruction_calc_size(t_instruction *self)
{
	t_argument	*argument;

	self->size = 1;
	if (self->op && self->arguments->count > 0)
	{
		if (self->op->use_types)
		{
			self->size += 1;
		}
		vector_start(self->arguments);
		while (vector_next(self->arguments, (void **)&argument))
		{
			self->size += argument_calc_size(argument, self->op->dir_ind);
		}
	}
	return (self->size);
}
