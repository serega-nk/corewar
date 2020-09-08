/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 23:04:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	lexer_tokenize_string(t_lexer *self, t_token *token)
{
	lexer_next(self);
	lexer_start(self);
	while (lexer_type(self) != TOKEN_TYPE_STRING)
	{
		if (lexer_eof(self))
			return (FALSE);
		lexer_next(self);
	}
	token->value = lexer_value(self);
	lexer_next(self);
	return (TRUE);
}
