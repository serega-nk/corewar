/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:07:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 08:59:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_command(t_parser *self)
{
	t_token		*token0;
	t_token		*token2;

	token0 = parser_peek(self, 0);
	token2 = parser_peek(self, 2);
	if (ft_strequ(token0->value, NAME_CMD_STRING) == FALSE &&
		ft_strequ(token0->value, COMMENT_CMD_STRING) == FALSE)
	{
		return (token_error(token0,
			"Invalid name of the command at token "));
	}
	if (hashtab_insert(self->commands, token0->value, token2->value) == FALSE)
	{
		return (token_error(token0,
			"Command is already defined in the scope "));
	}
	parser_move(self, 3);
	token0 = parser_peek(self, 0);
	if (token0->type != TOKEN_TYPE_WHITESPACE &&
		token0->type != TOKEN_TYPE_COMMENT &&
		token0->type != TOKEN_TYPE_ENDLINE)
	{
		return (token_error(token0, "Syntax error at token "));
	}
	return (TRUE);
}
