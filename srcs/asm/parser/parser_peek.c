/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:26:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 17:11:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*parser_peek(t_parser *self, int rel)
{
	t_token		*token;

	if (vector_get(self->lexer->tokens, self->pos + rel, (void **)&token))
		return (token);
	if (vector_get(self->lexer->tokens,	self->lexer->tokens->count - 1,
			(void **)&token) && token->type == TOKEN_TYPE_END)
		return (token);
	return (self->end);
}
