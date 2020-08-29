/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:47:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 21:33:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	(*g_funcs[])(t_lexer *, t_token *) = {
	&lexer_tokenize_word,
	&lexer_tokenize_string,
	&lexer_tokenize_comment,
	&lexer_tokenize_whitespace,
	&lexer_tokenize_spec,
	&lexer_tokenize_spec,
	&lexer_tokenize_spec,
	&lexer_tokenize_spec,
	&lexer_tokenize_spec
};

t_bool			lexer_tokenize(t_lexer *self)
{
	t_token			*token;

	while (lexer_eof(self) == FALSE)
	{
		token = token_create(lexer_type(self), self->ln, self->col);
		vector_push_back(self->tokens, token);
		if ((*g_funcs[token->type])(self, token) == FALSE)
		{
			ft_printf("Syntax error at token ");
			token_print(token);
			return (FALSE);
		}
	}
	return (TRUE);
}
