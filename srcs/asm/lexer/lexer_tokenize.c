/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 21:47:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 23:04:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize(t_lexer *self)
{
	char	current;

	current = lexer_peek(self, 0);
	if (current == STRING_CHAR)
		return (lexer_tokenize_string(self));
	if (current == COMMENT_CHAR)
		return (lexer_tokenize_comment(self));
	if (ft_index(WHITESPACE_CHARS, current) != -1)
		return (lexer_tokenize_whitespace(self));
	if (current == LABEL_CHAR)
		return (lexer_tokenize_label(self));
	if (current == SEPARATOR_CHAR)
		return (lexer_tokenize_separator(self));
	if (current == DIRECT_CHAR)
		return (lexer_tokenize_direct(self));
	if (current == ENDLINE_CHAR)
		return (lexer_tokenize_endline(self));
	if (current == END_CHAR)
		return (lexer_tokenize_end(self));
	return (lexer_tokenize_word(self));
}
