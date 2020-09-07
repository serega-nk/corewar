/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_whitespace.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:51:53 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 20:02:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	lexer_tokenize_whitespace(t_lexer *self, t_token *token)
{
	token = (t_token *)token;
	while (lexer_type(self) == TOKEN_TYPE_WHITESPACE)
		lexer_next(self);
	return (TRUE);
}
