/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:03:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disclasses.h"

t_decompiler		*decompiler_create(char *bytecode_fn)
{
	t_decompiler	*self;

	self = (t_decompiler *)ft_xmemalloc(sizeof(t_decompiler));
	self->bytecode_fn = bytecode_fn;
	self->bytecode_fd = -1;
	return (self);
}
