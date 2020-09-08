/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_prog_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:10:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_make_prog_size(t_compiler *self)
{
	t_instruction	*instruction;
	t_label			*label;

	self->prog_size = 0;
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		instruction->offset = self->prog_size;
		self->prog_size += instruction_calc_size(instruction);
	}
	hashtab_start(self->parser->labels);
	while (hashtab_next_kv(self->parser->labels, NULL, (void **)&label))
	{
		if (vector_get(self->parser->instructions, label->index,
				(void **)&instruction))
			label->offset = instruction->offset;
		else
			label->offset = self->prog_size;
	}
	return (TRUE);
}
