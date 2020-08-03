/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:02:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/03 22:37:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#define	COMMAND_CHAR '.'


t_bool	*lexer_get_next_token(t_lexer *self, t_token *atoken)
{
	char	ch;

	ch = lexer_peek(self);
	if (ch == ' ')
		return (TRUE);
	else if (ch == COMMAND_CHAR)
		return (lexer_command(self, atoken));
	else if (ch == STRING_CHAR)
		return (lexer_string(self, atoken));
	else if (ch == COMMENT_CHAR || ch == ALT_COMMENT_CHAR)
		return (lexer_comment(self, atoken));
	else

	if (lexer_peek(self) == '\0')
		return (NULL);
	
	self

	return (NULL);
}
