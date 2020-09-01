/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_instruction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:41:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 16:21:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_next_instruction(t_parser *self)
{
	t_instruction	*instruction;

	instruction = instruction_create();
	vector_push_back(self->instructions, instruction);
	instruction->token = parser_next(self);
	if ((instruction->op = op_get(instruction->token->value)) == NULL)
	{
		return (token_error(instruction->token,
			"Invalid name of the instruction"));
	}
	if (parser_accept(self, TOKEN_TYPE_WHITESPACE) == FALSE)
		return (token_error(parser_peek(self, 0), "Syntax error"));
	if (parser_next_arguments(self, instruction) == FALSE)
		return (FALSE);
	parser_accept(self, TOKEN_TYPE_WHITESPACE);
	parser_accept(self, TOKEN_TYPE_COMMENT);
	if (parser_accept(self, TOKEN_TYPE_ENDLINE) == FALSE)
		return (token_error(parser_peek(self, 0), "Syntax error"));
	return (TRUE);
}
