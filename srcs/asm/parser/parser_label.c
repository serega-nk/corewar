/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:01:51 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 20:39:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_label(t_parser *self)
{
	t_label		*label;

	label = label_create(parser_peek(self, 0)->value,
		self->instructions->count);
	if (hashtab_insert(self->labels, label->name, label) == FALSE)
	{
		ft_printf("Label '%s' is already defined in the scope ", label->name);
		token_print(parser_peek(self, 0));
		label_destroy(&label);
		return (FALSE);
	}
	parser_move(self, 2);
	if (parser_has_skip(self) == FALSE)
	{
		ft_printf("Syntax error at token ");
		token_print(parser_peek(self, 0));
		return (FALSE);
	}
	ft_printf("LABEL %s: = %d\n", label->name, label->index);
	return (TRUE);
}
