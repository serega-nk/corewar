/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_skip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:46:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/30 19:05:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_skip(t_parser *self)
{
	t_token		*token0;
	t_token		*token1;

	token0 = parser_peek(self, 0);
	token1 = parser_peek(self, 1);
	if (token0->type == TOKEN_TYPE_COMMENT &&
		token1->type != TOKEN_TYPE_ENDLINE)
	{
		return (token_error(token1, "Syntax error at token "));
	}
	if (token0->type != TOKEN_TYPE_ENDLINE &&
		token1->type == TOKEN_TYPE_END)
	{
		return (token_error(token0,
			"Syntax error - unexpected end of input, after token "));
	}
	parser_move(self, 1);
	return (TRUE);
}
