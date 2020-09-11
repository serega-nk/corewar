/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_make_bytecode.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 21:03:51 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 00:15:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static char		calc_types(t_instruction *self)
{
	char		types;
	int			index;
	t_argument	*argument;

	types = 0;
	index = 4;
	vector_start(self->arguments);
	while (index-- > 1)
	{
		if (vector_next(self->arguments, (void **)&argument))
		{
			if (argument->arg_type & T_REG)
				types |= REG_CODE << (index * 2);
			else if (argument->arg_type & T_DIR)
				types |= DIR_CODE << (index * 2);
			else if (argument->arg_type & T_IND)
				types |= IND_CODE << (index * 2);
		}
	}
	return (types);
}

void			instruction_make_bytecode(t_instruction *self)
{
	t_argument	*argument;
	int			pos;

	pos = 0;
	self->bytecode = ft_xmemalloc(self->size);
	self->bytecode[pos++] = self->op->code;
	if (self->op->use_types)
		self->bytecode[pos++] = calc_types(self);
	vector_start(self->arguments);
	while (vector_next(self->arguments, (void **)&argument))
	{
		ft_memcpy(self->bytecode + pos, &argument->number, argument->size);
		ft_memrev(self->bytecode + pos, argument->size);
		pos += argument->size;
	}
}
