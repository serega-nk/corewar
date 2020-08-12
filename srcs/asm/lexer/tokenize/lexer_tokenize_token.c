/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:19:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 16:31:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize_token(t_lexer *self, t_token_type type)
{
	t_token	*token;

	token = token_create(type, self->ln, self->col);
	token->start = self->pos;
	lexer_next(self);
	return (token);
}
