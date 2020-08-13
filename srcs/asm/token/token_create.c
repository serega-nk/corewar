/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:34:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 18:42:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*token_create(t_token_type type, int ln, int col)
{
	t_token	*self;

	self = (t_token *)ft_xmemalloc(sizeof(t_token));
	self->type = type;
	self->ln = ln;
	self->col = col;
	return (self);
}
