/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_whitespace.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:51:53 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 23:01:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize_whitespace(t_lexer *self)
{
	t_token	*token;

	token = token_create(TOKEN_TYPE_WHITESPACE);
	while (lexer_type(self) == TOKEN_TYPE_WHITESPACE)
		lexer_next(self);
	return (token);
}
