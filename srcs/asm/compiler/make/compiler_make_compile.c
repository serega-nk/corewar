/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_compile.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:27:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 06:22:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		compiler_make_compile_prog_size(t_compiler *self)
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
}

static void		compiler_make_compile_convert_labels(t_compiler *self)
{
	t_instruction	*instruction;
	t_argument		*argument;

	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		vector_start(instruction->arguments);
		while (vector_next(instruction->arguments, (void **)&argument))
		{
			if (argument->label)
			{
				argument->number = \
					argument->label->offset - instruction->offset;
			}
		}
	}
}

static void		compiler_make_compile_instructions(t_compiler *self)
{
	t_instruction	*instruction;

	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		instruction_make_bytecode(instruction);
	}
}

static void		compiler_make_compile_header(t_compiler *self)
{
	unsigned int	magic;
	
	magic = COREWAR_EXEC_MAGIC;	
	ft_memcpy_rev(&self->header.magic, &magic, sizeof(magic));
	ft_strcpy(self->header.prog_name, self->parser->cmd_name);
	ft_memcpy_rev(&self->header.prog_size, &self->prog_size,
	 	sizeof(self->header.prog_size));
	ft_strcpy(self->header.comment, self->parser->cmd_comment);
}

t_bool			compiler_make_compile(t_compiler *self)
{
	self->lexer = lexer_create(self->source_data, self->source_size);
	if (lexer_tokenize(self->lexer) == FALSE)
		return (FALSE);
	self->parser = parser_create(self->lexer->tokens);
	if (parser_make(self->parser) == FALSE)
		return (FALSE);
	compiler_make_compile_prog_size(self);
	compiler_make_compile_convert_labels(self);
	compiler_make_compile_instructions(self);
	compiler_make_compile_header(self);
	return (TRUE);
}
