/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:07:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 14:09:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_bool	parser_next_command_case_name(t_parser *self, t_token *t0,
	t_token *t2)
{
	size_t	length;

	if (self->cmd_name)
		return (parser_error(self, t0, "Command is already defined"));
	length = ft_strlen(t2->value);
	if (length == 0)
		return (parser_error(self, t2, "Champion name empty"));
	if (length > PROG_NAME_LENGTH)
	{
		return (parser_errorf(self, t2,	ft_xprintf(
			"Champion name too long (Max length %d)", PROG_NAME_LENGTH)));
	}
	self->cmd_name = t2->value;
	return (TRUE);
}

static t_bool	parser_next_command_case_comment(t_parser *self, t_token *t0,
	t_token *t2)
{
	size_t	length;

	if (self->cmd_comment)
		return (parser_error(self, t0, "Command is already defined"));
	length = ft_strlen(t2->value);
	if (length > COMMENT_LENGTH)
	{
		return (parser_errorf(self, t2,	ft_xprintf(
			"Champion comment too long (Max length %d)", COMMENT_LENGTH)));
	}
	self->cmd_comment = t2->value;
	return (TRUE);
}

static t_bool	parser_next_command_case(t_parser *self, t_token *t0,
	t_token *t2)
{
	if (ft_strequ(t0->value, NAME_CMD_STRING))
		return (parser_next_command_case_name(self, t0, t2));
	else if (ft_strequ(t0->value, COMMENT_CMD_STRING))
		return (parser_next_command_case_comment(self, t0, t2));
	else
		return (parser_error(self, t0, "Invalid name of the command"));
}

t_bool			parser_next_command(t_parser *self)
{
	t_token		*t0;
	t_token		*t2;

	t0 = parser_peek(self, 0);
	t2 = parser_peek(self, 2);
	if (parser_accept(self, TOKEN_TYPE_WORD) == FALSE ||
		parser_accept(self, TOKEN_TYPE_WHITESPACE) == FALSE ||
		parser_accept(self, TOKEN_TYPE_STRING) == FALSE)
		return (parser_error(self, parser_peek(self, 0), "Syntax error"));
	if (parser_next_command_case(self, t0, t2) == FALSE)
		return (FALSE);
	if (parser_accept(self, TOKEN_TYPE_WHITESPACE) == FALSE &&
		parser_accept(self, TOKEN_TYPE_COMMENT) == FALSE &&
		parser_accept(self, TOKEN_TYPE_ENDLINE) == FALSE)
		return (parser_error(self, parser_peek(self, 0), "Syntax error"));
	return (TRUE);
}
