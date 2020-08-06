/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_whitespace.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:51:53 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 23:05:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*lexer_tokenize_whitespace(t_lexer *self)
{
	t_token	*token;
	char	current;

	token = token_create(TOKEN_TYPE_WHITESPACE, self->ln, self->col);
	while (TRUE)
	{
		current = lexer_next(self);
		if (ft_index(WHITESPACE_CHARS, current) == -1)
			break ;
	}
	return (token);
}
