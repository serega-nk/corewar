/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_calc_prog_size.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:14:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 21:14:28 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	calc_size(t_instruction *instruction)
{
	size_t		size;
	t_argument	*argument;

	size = 1;
	vector_start(instruction->arguments);
	while (vector_next(instruction->arguments, (void **)&argument))
	{
		if (argument->arg_type & T_REG)
			size += REG_SIZE;
		else if (argument->arg_type & T_DIR)
			size += DIR_SIZE;
		else if (argument->arg_type & T_IND)
			size += IND_SIZE;
	}
	return (size);
}

void			compiler_make_calc_prog_size(t_compiler *self)
{
	t_instruction	*instruction;
	t_label			*label;	

	self->header.prog_size = 0;
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		instruction->offset = self->header.prog_size;
		instruction->size = calc_size(instruction);
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
