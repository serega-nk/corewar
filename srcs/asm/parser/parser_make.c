/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:23:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 16:22:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	parser_make_head(t_parser *self)
{
	while (parser_eof(self) == FALSE)
	{
		if (parser_has_command(self))
		{
			if (parser_next_command(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_skip(self))
		{
			if (parser_next_skip(self) == FALSE)
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
			if (parser_next_label(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_instruction(self))
		{
			if (parser_next_instruction(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_skip(self))
		{
			if (parser_next_skip(self) == FALSE)
				return (FALSE);
		}
		else
			return (token_error(parser_peek(self, 0), "Syntax error"));
	}
	return (TRUE);
}

static t_bool	parser_make_complete(t_parser *self)
{
	t_argument	*argument;

	vector_start(self->convert_labels);
	while (vector_next(self->convert_labels, (void **)&argument))
	{
		if (hashtab_get(self->labels, argument->token->value,
			(void **)&argument->label) == FALSE)
		{
			return (token_error(argument->token, "Label not defined"));
		}
	}
	return (TRUE);
}

t_bool			parser_make(t_parser *self)
{
	return (parser_make_head(self) &&
			parser_make_body(self) &&
			parser_make_complete(self));
}
