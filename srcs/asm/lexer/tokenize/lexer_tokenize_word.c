/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:30:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 20:09:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	lexer_tokenize_word(t_lexer *self, t_token *token)
{
	lexer_start(self);
	while (lexer_type(self) == TOKEN_TYPE_WORD)
		lexer_next(self);
	token->value = lexer_value(self);
	return (TRUE);
}
