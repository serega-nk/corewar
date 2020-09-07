/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_bytecode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:38:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:10:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make_bytecode(t_compiler *self)
{
	t_instruction	*instruction;
	size_t			pos;

	self->bytecode_size = sizeof(self->header) + self->prog_size;
	self->bytecode_data = ft_xmemalloc(self->bytecode_size);
	ft_memcpy(self->bytecode_data, &self->header, sizeof(self->header));
	pos = sizeof(self->header);
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		instruction_make_bytecode(instruction);
		ft_memcpy(self->bytecode_data + pos,
			instruction->bytecode, instruction->size);
		pos += instruction->size;
	}
	return (TRUE);
}
