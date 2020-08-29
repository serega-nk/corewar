/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:59:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 20:03:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser	*parser_create(t_vector *tokens)
{
	t_parser	*self;

	self = (t_parser *)ft_xmemalloc(sizeof(t_parser));
	self->tokens = tokens;
	self->end = token_create(TOKEN_TYPE_END, 0, 0);
	self->labels = hashtab_create();
	self->headers = hashtab_create();
	self->instructions = vector_create();
	return (self);
}
