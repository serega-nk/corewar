/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:07:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 23:07:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static char		*make_bytecode_fn(char *source_fn)
{
	size_t		length;

	length = ft_strlen(source_fn);
	if (length >= 2 && ft_strequ(source_fn + length - 2, ".s"))
		length -= 2;
	return (ft_xprintf("%.*s.cor", length, source_fn));
}

t_compiler		*compiler_create(char *source_fn)
{
	t_compiler	*self;

	self = (t_compiler *)ft_xmemalloc(sizeof(t_compiler));
	self->source_fn = source_fn;
	self->bytecode_fn = make_bytecode_fn(source_fn);
	self->source_fd = -1;
	self->bytecode_fd = -1;
	return (self);
}
