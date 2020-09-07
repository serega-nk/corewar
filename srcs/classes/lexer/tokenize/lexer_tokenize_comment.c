/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_comment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:29:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 20:37:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	lexer_tokenize_comment(t_lexer *self, t_token *token)
{
	token = (t_token *)token;
	while (lexer_type(self) != TOKEN_TYPE_ENDLINE)
	{
		if (lexer_eof(self))
			return (FALSE);
		lexer_next(self);
	}
	return (TRUE);
}
