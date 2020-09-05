/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 22:27:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 00:13:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	compiler_print_instructions(t_compiler *self)
{
	t_instruction	*instruction;

	ft_printf("=== INSTRUCTIONS: ===\n");
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		instruction_print(instruction);
		ft_printf("\n");
	}
}
