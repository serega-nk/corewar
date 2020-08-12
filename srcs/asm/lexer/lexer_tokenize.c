/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:47:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 23:38:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize(t_lexer *self)
{
	t_token_type	type;

	type = lexer_type(self);
	if (type == TOKEN_TYPE_WORD)
		return (lexer_tokenize_word(self));
	if (type == TOKEN_TYPE_WHITESPACE)
		return (lexer_tokenize_whitespace(self));
	if (type == TOKEN_TYPE_COMMENT)
		return (lexer_tokenize_comment(self));
	if (type == TOKEN_TYPE_STRING)
		return (lexer_tokenize_string(self));
	return (lexer_tokenize_token(self, type));
}
