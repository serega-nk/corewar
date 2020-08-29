/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:07:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 20:28:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_header(t_parser *self)
{
	char		*key;
	char		*value;

	key = parser_peek(self, 0)->value;
	value = parser_peek(self, 2)->value;
	if (hashtab_insert(self->headers, key, value) == FALSE)
	{
		ft_printf("Header '%s' is already defined in the scope ", key);
		token_print(parser_peek(self, 0));
		return (FALSE);
	}
	parser_move(self, 3);
	if (parser_has_skip(self) == FALSE) {
		ft_printf("Syntax error at token ");
		token_print(parser_peek(self, 0));
		return (FALSE);
	}
	ft_printf("HEADER! key = %s, value = %s\n", key, value);
	return (TRUE);
}
