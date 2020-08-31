/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:47:19 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 15:40:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_make_arguments(t_parser *self, t_instruction *instruction)
{
	int			index;
	t_arg_type	arg_type;

	index = 0;
	while (index < instruction->op->argc)
	{
		arg_type = instruction->op->args[index++];
		parser_accept(self, TOKEN_TYPE_WHITESPACE);
		if (parser_make_argument(self, instruction, arg_type) == FALSE)
			return (FALSE);
		parser_accept(self, TOKEN_TYPE_WHITESPACE);
		
		if (parser_accept(self, TOKEN_TYPE_SEPARATOR) == FALSE)
			break ;
	}
	if (index != instruction->op->argc)
	{
		return (token_error(instruction->token,
			"Invalid parameter count for instruction"));
	}
	return (TRUE);
}
