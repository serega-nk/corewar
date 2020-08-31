/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:23:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 15:29:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	parser_make_head(t_parser *self)
{
	while (parser_eof(self) == FALSE)
	{
		if (parser_has_command(self))
		{
			if (parser_make_command(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_skip(self))
		{
			if (parser_make_skip(self) == FALSE)
				return (FALSE);
		}
		else
			break ;
	}
	if (hashtab_get(self->commands, NAME_CMD_STRING, NULL) == FALSE ||
		hashtab_get(self->commands, COMMENT_CMD_STRING, NULL) == FALSE)
	{
		return (token_error(parser_peek(self, 0),
			"Expected to enter the command"));
	}
	return (TRUE);
}

static t_bool	parser_make_body(t_parser *self)
{
	while (parser_eof(self) == FALSE)
	{
		if (parser_has_label(self))
		{
			if (parser_make_label(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_instruction(self))
		{
			if (parser_make_instruction(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_skip(self))
		{
			if (parser_make_skip(self) == FALSE)
				return (FALSE);
		}
		else
			return (token_error(parser_peek(self, 0), "Syntax error"));
	}
	return (TRUE);
}

static t_bool	parser_make_complete(t_parser *self)
{
	// t_instruction	*instruction;
	// t_argument		*argument;
	// int				index;
	// t_arg_type		arg_type;

	// vector_start(self->instructions);
	// while (vector_next(self->instructions, (void **)&instruction))
	// {
	// 	if (instruction->op->argc != (int)instruction->arguments->count)
	// 	{
	// 		return (token_error(instruction->token, 
	// 			"Invalid parameter count for instruction"));
	// 	}
	// 	index = 0;
	// 	while (index < instruction->op->argc)
	// 	{
	// 		arg_type = instruction->op->args[index];
	// 		if (!vector_get(instruction->arguments, index, (void **)&argument))
	// 			return (token_error(instruction->token, "Invalid instruction"));
	// 		if (argument->arg_type & T_LAB)
	// 		{
	// 			argument->arg_type ^= T_LAB;
	// 			argument->arg_type |= T_IND;

	// 		}

	// 		if ((argument->arg_type & T_REG && !(arg_type & T_REG)) ||
	// 			(argument->arg_type & T_DIR && !(arg_type & T_DIR)) ||
	// 			(argument->arg_type & T_IND && !(arg_type & T_IND)))
	// 		{
	// 			return (token_error(instruction->token,
	// 				"Invalid parameter type for instruction"));
	// 		}
	// 		index++;
	// 	}
	// }
	if (self)
		return (TRUE);
	return (TRUE);
}

t_bool			parser_make(t_parser *self)
{
	return (parser_make_head(self) &&
			parser_make_body(self) &&
			parser_make_complete(self));
}
