/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_convert_labels.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:35:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 22:51:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make_convert_labels(t_compiler *self)
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
	return (TRUE);
}
