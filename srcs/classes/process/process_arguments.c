/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:51:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:21:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool			process_arguments(t_process *self)
{
	t_argument	*argument;
	size_t		index;

	index = 0;
	while (index < self->op->arg_count)
	{
		argument = argument_create();
		vector_push_back(self->arguments, argument);
		argument->arg_type = self->arg_types[index];
		argument_calc_size(argument, self->op->dir_ind);
		vm_read(self->vm, self->pc + self->step,
			&argument->number, argument->size);
		ft_memrev(&argument->number, argument->size);
		ft_signed(&argument->number, argument->size, sizeof(argument->number));
		process_step(self, argument->size);
		self->args[index] = argument->number;
		index++;
	}
	return (TRUE);
}
