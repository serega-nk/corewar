/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 23:04:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 23:39:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token				*lexer_tokenize_string(t_lexer *self)
{
	t_token			*token;
	t_token_type	type;

	token = token_create(TOKEN_TYPE_STRING);
	
	while (TRUE)
	{
		type = lexer_type(lexer_next(self));
		if (type == TOKEN_TYPE_END)
		{
			ft_printf("Syntax error at token ");

		}
		if (type == TOKEN_TYPE_STRING)
			break ;
	}
	return (token);
	// start = self->pos;
	// while (TRUE)
	// {
	// 	current = lexer_next(self);

	// 	if (current == END_CHAR)
	// 	{
	// 		ft_printf("Syntax error at token ");
	// 		token_print(token);
	// 		token_destroy(&token);
	// 		return (NULL);
	// 	}
	// 	if (current == STRING_CHAR)
	// 		break ;
	// }
	// if (start < self->pos)
	// {
	// 	token->value = (char *)ft_xcheck(
	// 		(void *)ft_strndup(self->input + start, self->pos - start - 1));
	// }
	return (token);
}
