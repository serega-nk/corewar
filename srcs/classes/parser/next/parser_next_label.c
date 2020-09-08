/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_label.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:01:51 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:58:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	parser_next_label(t_parser *self)
{
	t_token		*token;
	t_label		*label;

	token = parser_peek(self, 0);
	if (label_name_check(token->value) == FALSE)
		return (parser_error(self, token, "Invalid name of the label"));
	label = label_create(token, token->value, self->instructions->count);
	if (hashtab_insert(self->labels, label->name, label) == FALSE)
	{
		label_destroy(&label);
		return (parser_error(self, token, "Label is already defined"));
	}
	parser_move(self, 2);
	token = parser_peek(self, 0);
	if (token->type != TOKEN_TYPE_WORD &&
		token->type != TOKEN_TYPE_WHITESPACE &&
		token->type != TOKEN_TYPE_COMMENT &&
		token->type != TOKEN_TYPE_ENDLINE)
	{
		return (parser_error(self, token, "Syntax error"));
	}
	return (TRUE);
}
