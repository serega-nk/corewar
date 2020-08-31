/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:41:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 08:56:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		parser_instruction_argument_prefix(t_parser *self,
	t_argument *argument)
{
	if (parser_peek(self, 0)->type == TOKEN_TYPE_DIRECT)
	{
		argument->arg_type |= T_DIR;
		parser_move(self, 1);
	}
	if (parser_peek(self, 0)->type == TOKEN_TYPE_LABEL)
	{
		argument->arg_type |= T_LAB;
		parser_move(self, 1);
	}
}

static t_bool	parser_instruction_argument(t_parser *self,
	t_argument *argument)
{
	t_token		*token;
	char		*ptr;

	parser_instruction_argument_prefix(self, argument);
	token = parser_peek(self, 0);
	parser_move(self, 1);
	if (token->type != TOKEN_TYPE_WORD)
		return (token_error(token, "Invalid argument at token "));
	if (argument->arg_type & T_LAB)
	{
		if (label_name_check(token->value) == FALSE)
			return (token_error(token, "Invalid name of the label at token "));
		argument->label = token->value;
		return (TRUE);
	}
	ptr = token->value;
	if (parse_skip(&ptr, "r"))
		argument->arg_type |= T_REG;
	if ((parse_int(&ptr, &argument->number) && parse_none(&ptr)) == FALSE)
		return (token_error(token, "Invalid argument at token "));
	if (argument->arg_type & T_REG &&
		(argument->number < 0 || argument->number >= REG_NUMBER))
		return (token_error(token, "Invalid register number at token "));
	argument->token = token;
	return (TRUE);
}

t_bool			parser_instruction_arguments(t_parser *self,
	t_instruction *instruction)
{
	t_argument		*argument;

	while (TRUE)
	{
		argument = argument_create();
		vector_push_back(instruction->arguments, argument);
		if (parser_instruction_argument(self, argument) == FALSE)
			return (FALSE);
		if (parser_peek(self, 0)->type == TOKEN_TYPE_WHITESPACE)
			parser_move(self, 1);
		if (parser_peek(self, 0)->type != TOKEN_TYPE_SEPARATOR)
			break ;
		parser_move(self, 1);
	}
	return (TRUE);
}

t_bool			parser_instruction_check(t_parser *self,
	t_instruction *instruction)
{
	if (self || instruction)
		return (TRUE);
	return (TRUE);
}

t_bool			parser_instruction(t_parser *self)
{
	t_op			*op;
	t_instruction	*instruction;

	if ((op = op_get(parser_peek(self, 0)->value)) == NULL)
	{
		return (token_error(parser_peek(self, 0),
			"Invalid name of the instruction at token "));
	}
	instruction = instruction_create(op, parser_peek(self, 0));
	vector_push_back(self->instructions, instruction);
	parser_move(self, 2);
	if (parser_instruction_arguments(self, instruction) == FALSE)
		return (FALSE);
	if (parser_peek(self, 0)->type == TOKEN_TYPE_WHITESPACE)
		parser_move(self, 1);
	if (parser_peek(self, 0)->type == TOKEN_TYPE_COMMENT)
		parser_move(self, 1);
	if (parser_peek(self, 0)->type != TOKEN_TYPE_ENDLINE)
	{
		return (token_error(parser_peek(self, 0),
			"Invalid instruction at token "));
	}
	parser_move(self, 1);
	return (parser_instruction_check(self, instruction));
}
