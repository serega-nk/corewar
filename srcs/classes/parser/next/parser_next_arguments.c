/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:47:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 18:52:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	parser_next_arguments(t_parser *self, t_instruction *instruction)
{
	t_arg_type	arg_type;

	while (instruction->arguments->count < instruction->op->arg_count)
	{
		arg_type = instruction->op->arg_types[instruction->arguments->count];
		parser_accept(self, TOKEN_TYPE_WHITESPACE);
		if (parser_next_argument(self, instruction, arg_type) == FALSE)
			return (FALSE);
		parser_accept(self, TOKEN_TYPE_WHITESPACE);
		if (parser_accept(self, TOKEN_TYPE_SEPARATOR) == FALSE)
			break ;
	}
	if (instruction->arguments->count != instruction->op->arg_count)
	{
		return (parser_error(self, instruction->token,
			"Invalid parameter count for instruction"));
	}
	return (TRUE);
}
