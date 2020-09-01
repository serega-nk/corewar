/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:59:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 17:12:10 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser	*parser_create(t_lexer *lexer)
{
	t_parser	*self;

	self = (t_parser *)ft_xmemalloc(sizeof(t_parser));
	self->lexer = lexer;
	self->end = token_create(TOKEN_TYPE_END, 0, 0);
	self->labels = hashtab_create();
	self->commands = hashtab_create();
	self->instructions = vector_create();
	self->convert_labels = vector_create();
	return (self);
}
