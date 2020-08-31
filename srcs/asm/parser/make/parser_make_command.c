/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:07:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 11:02:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_make_command(t_parser *self)
{
	t_token		*t0;
	t_token		*t2;

	t0 = parser_peek(self, 0);
	t2 = parser_peek(self, 2);
	if (ft_strequ(t0->value, NAME_CMD_STRING) == FALSE &&
		ft_strequ(t0->value, COMMENT_CMD_STRING) == FALSE)
		return (token_error(t0, "Invalid name of the command"));
	if (hashtab_insert(self->commands, t0->value, t2->value) == FALSE)
		return (token_error(t0, "Command is already defined in the scope"));
	parser_move(self, 3);
	t0 = parser_peek(self, 0);
	if (t0->type != TOKEN_TYPE_WHITESPACE &&
		t0->type != TOKEN_TYPE_COMMENT &&
		t0->type != TOKEN_TYPE_ENDLINE)
		return (token_error(t0, "Syntax error"));
	return (TRUE);
}
