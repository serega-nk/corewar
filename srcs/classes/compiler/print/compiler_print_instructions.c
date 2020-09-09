/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 22:27:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:31:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	compiler_print_instructions(t_compiler *self)
{
	t_instruction	*instruction;
	t_argument		*argument;

	ft_printf("=== INSTRUCTIONS: ===\n");
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		ft_printf("%s\n", instruction_repr(instruction));
		vector_start(instruction->arguments);
		while (vector_next(instruction->arguments, (void **)&argument))
		{
			ft_printf("%s\n", argument_repr(argument));
		}
	}
}
