/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 00:23:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/30 17:48:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	parser_make_head(t_parser *self)
{
	while (parser_has_next(self))
	{
		if (parser_has_command(self))
		{
			if (parser_command(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_skip(self))
		{
			if (parser_skip(self) == FALSE)
				return (FALSE);
		}
		else
			return (TRUE);
	}
	return (TRUE);
}

static t_bool	parser_make_body(t_parser *self)
{
	while (parser_has_next(self))
	{
		if (parser_has_label(self))
		{
			if (parser_label(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_instruction(self))
		{
			if (parser_instruction(self) == FALSE)
				return (FALSE);
		}
		else if (parser_has_skip(self))
		{
			if (parser_skip(self) == FALSE)
				return (FALSE);
		}
		else
			return (token_error(parser_peek(self, 0),
				"Syntax error at token "));
	}
	return (TRUE);
}

t_bool			parser_make(t_parser *self)
{
	return (parser_make_head(self) &&
			parser_make_body(self));
}
