/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_repr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:09:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:05:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

char	*instruction_repr(t_instruction *self)
{
	ft_strdel(&self->repr);
	self->repr = ft_xprintf("[%03d:%03d] INSTRUCTION: " \
		"name = %s, code = %#.2x, size = %lu, offset = %lu, arg = %d",
		self->token->ln, self->token->col, self->op->name, self->op->code,
		self->size, self->offset, self->arguments->count);
	return (self->repr);
}
