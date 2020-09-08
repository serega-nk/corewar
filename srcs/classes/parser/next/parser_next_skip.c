/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_skip.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:46:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:58:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	parser_next_skip(t_parser *self)
{
	if (parser_peek(self, 0)->type == TOKEN_TYPE_COMMENT &&
		parser_peek(self, 1)->type != TOKEN_TYPE_ENDLINE)
	{
		return (parser_error(self, parser_peek(self, 1), "Syntax error"));
	}
	if (parser_peek(self, 0)->type != TOKEN_TYPE_ENDLINE &&
		parser_peek(self, 1)->type == TOKEN_TYPE_END)
	{
		return (parser_error(self, parser_peek(self, 0),
			"Syntax error - unexpected end of input"));
	}
	parser_move(self, 1);
	return (TRUE);
}
