/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:52:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 23:38:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_list		*lexer_tokens(t_lexer *self)
{
	t_list	*tokens;

	tokens = list_create();
	while (lexer_eof(self) == FALSE)
		list_push_back(tokens, lexer_tokenize(self));
	return (tokens);
}
