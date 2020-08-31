/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_has_skip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:46:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/30 17:28:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_has_skip(t_parser *self)
{
	t_token		*token;

	token = parser_peek(self, 0);
	return (token->type == TOKEN_TYPE_WHITESPACE ||
			token->type == TOKEN_TYPE_COMMENT ||
			token->type == TOKEN_TYPE_ENDLINE);
}
