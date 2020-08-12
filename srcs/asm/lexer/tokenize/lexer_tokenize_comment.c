/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:29:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 23:52:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize_comment(t_lexer *self)
{
	t_token	*token;

	token = token_create(TOKEN_TYPE_COMMENT);
	while (lexer_eof(self) == FALSE && lexer_type(self) != TOKEN_TYPE_ENDLINE)
		lexer_next(self);
	return (token);
}
