/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:58:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:11:28 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_bool	check_arg_type(t_arg_type arg_type, t_arg_type allow)
{
	if (((arg_type & T_REG) && (arg_type != T_REG)) ||
		((arg_type & T_DIR) && (arg_type & T_IND)) ||
		((arg_type & T_REG) && !(allow & T_REG)) ||
		((arg_type & T_DIR) && !(allow & T_DIR)) ||
		((arg_type & T_IND) && !(allow & T_IND)))
	{
		return (FALSE);
	}
	return (TRUE);
}

t_bool			parser_next_argument_parse_token(t_parser *self,
	t_argument *argument)
{
	char		*ptr;

	if (argument->arg_type & T_LAB)
	{
		if (label_name_check(argument->token->value) == FALSE)
			return (parser_error(self, argument->token, "Invalid name label"));
	}
	else
	{
		ptr = argument->token->value;
		if (parse_skip(&ptr, "r"))
			argument->arg_type |= T_REG;
		if ((parse_long(&ptr, &argument->number) && parse_none(&ptr)) == FALSE)
			return (parser_error(self, argument->token, "Invalid argument"));
		if (argument->arg_type & T_REG &&
			(argument->number <= 0 || argument->number > REG_NUMBER))
		{
			return (parser_error(self, argument->token,
				"Invalid register number"));
		}
	}
	if (!(argument->arg_type & T_REG) && !(argument->arg_type & T_DIR))
		argument->arg_type |= T_IND;
	return (TRUE);
}

t_bool			parser_next_argument(t_parser *self,
	t_instruction *instruction, t_arg_type allow)
{
	t_argument	*argument;

	argument = argument_create();
	vector_push_back(instruction->arguments, argument);
	if (parser_accept(self, TOKEN_TYPE_DIRECT))
		argument->arg_type |= T_DIR;
	if (parser_accept(self, TOKEN_TYPE_LABEL))
	{
		argument->arg_type |= T_LAB;
		vector_push_back(self->convert_labels, (void **)argument);
	}
	argument->token = parser_peek(self, 0);
	if (parser_accept(self, TOKEN_TYPE_WORD) == FALSE)
		return (parser_error(self, parser_peek(self, 0), "Invalid argument"));
	if (parser_next_argument_parse_token(self, argument) == FALSE)
		return (FALSE);
	if (check_arg_type(argument->arg_type, allow) == FALSE)
	{
		return (parser_error(self, argument->token,
			"Invalid parameter type for instruction"));
	}
	return (TRUE);
}
