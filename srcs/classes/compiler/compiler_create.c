/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:07:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:09:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*make_bytecode_fn(char *source_fn)
{
	char		*basename;
	char		*bytecode_fn;
	size_t		length;

	basename = ft_xstrdup(source_fn);
	length = ft_strlen(basename);
	if (length >= 2 && ft_strequ(basename + length - 2, ".s"))
		basename[length - 2] = '\0';
	bytecode_fn = ft_xstrdup2(basename, ".cor");
	ft_strdel(&basename);
	return (bytecode_fn);
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
