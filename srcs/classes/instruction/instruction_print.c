/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:56:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 20:54:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	instruction_print(t_instruction *self)
{
	t_argument	*argument;

	ft_printf("[%03d:%03d] INSTRUCTION: name = %s, code = %#.2x",
		self->token->ln, self->token->col, self->op->name, self->op->code);
	ft_printf(", size = %lu, offset = %lu, arg = %d",
		self->size, self->offset, self->arguments->count);
	vector_start(self->arguments);
	while (vector_next(self->arguments, (void **)&argument))
	{
		ft_printf("\n");
		argument_print(argument);
	}
}
