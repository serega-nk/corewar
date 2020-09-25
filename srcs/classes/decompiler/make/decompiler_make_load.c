/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make_load.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:13:20 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/25 15:44:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool	decompiler_make_load(t_decompiler *self)
{
	self->bytecode_fd = open(self->bytecode_fn, O_RDONLY);
	if (self->bytecode_fd >= 0)
	{
		self->bytecode_size = ft_get_size(self->bytecode_fd);
		self->bytecode_data = ft_xmalloc(self->bytecode_size);
		if (ft_readall(self->bytecode_fd, self->bytecode_data,
			self->bytecode_size))
		{
			return (TRUE);
		}
	}
	decompiler_errorf(self, ft_xprintf(
		"Can't read bytecode file %s", self->bytecode_fn));
	return (FALSE);
}
