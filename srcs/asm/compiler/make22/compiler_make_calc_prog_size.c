/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_calc_prog_size.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:14:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/02 23:39:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			compiler_make_calc_prog_size(t_compiler *self)
{
	t_instruction	*instruction;
	t_label			*label;	

	self->header.prog_size = 0;
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		instruction->offset = self->header.prog_size;
		instruction->size = instruction_calc_size(instruction);
		self->header.prog_size += instruction->size;
	}
	hashtab_start(self->parser->labels);
	while (hashtab_next_kv(self->parser->labels, NULL, (void **)&label))
	{
		if (vector_get(self->parser->instructions, label->index,
				(void **)&instruction))
			label->offset = instruction->offset;
		else
			label->offset = self->header.prog_size;
	}
}
