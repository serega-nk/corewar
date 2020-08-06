/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:16:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 22:57:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lexer		*lexer_create(char *input, size_t length)
{
	t_lexer	*self;

	self = (t_lexer *)ft_xmemalloc(sizeof(t_lexer));
	self->input = input;
	self->length = length;
	self->ln = 1;
	self->col = 1;
	return (self);
}
