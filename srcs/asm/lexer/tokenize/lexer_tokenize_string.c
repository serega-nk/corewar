/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 23:04:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 23:12:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize_string(t_lexer *self)
{
	t_token	*token;
	size_t	save;
	char	current;

	token = token_create(TOKEN_TYPE_STRING, self->ln, self->col);
	lexer_next(self);
	save = self->pos;
	while (TRUE)
	{
		if ()
		current = lexer_next(self);
		if (ft_index(WHITESPACE_CHARS, current) == -1)
			break ;
	}
	token->value = (char *)ft_xcheck(
		(void *)ft_strndup(self->input + save, self->pos - save));
	return (token);
}
