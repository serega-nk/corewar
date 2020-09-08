/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:29:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_token_type	lexer_type(t_lexer *self)
{
	char		ch;

	ch = lexer_peek(self, 0);
	if (ft_index(WHITESPACE_CHARS, ch) != -1)
		return (TOKEN_TYPE_WHITESPACE);
	if (ch == COMMENT_CHAR)
		return (TOKEN_TYPE_COMMENT);
	if (ch == STRING_CHAR)
		return (TOKEN_TYPE_STRING);
	if (ch == LABEL_CHAR)
		return (TOKEN_TYPE_LABEL);
	if (ch == SEPARATOR_CHAR)
		return (TOKEN_TYPE_SEPARATOR);
	if (ch == DIRECT_CHAR)
		return (TOKEN_TYPE_DIRECT);
	if (ch == ENDLINE_CHAR)
		return (TOKEN_TYPE_ENDLINE);
	if (ch == END_CHAR || ch < 0)
		return (TOKEN_TYPE_END);
	return (TOKEN_TYPE_WORD);
}
