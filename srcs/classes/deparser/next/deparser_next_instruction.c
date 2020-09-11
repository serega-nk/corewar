/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_next_instruction.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:39:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:39:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool				deparser_next_instruction(t_deparser *self)
{
	t_instruction	*instruction;
	size_t			index;

	instruction = instruction_create();
	vector_push_back(self->instructions, instruction);
	if (deparser_next_op(self, instruction) == FALSE)
		return (FALSE);
	if (deparser_next_arg_types(self, instruction) == FALSE)
		return (FALSE);
	index = 0;
	while (index < instruction->op->arg_count)
	{
		if (deparser_next_argument(self, instruction, index) == FALSE)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
