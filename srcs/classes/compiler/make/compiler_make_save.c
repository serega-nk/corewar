/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_save.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:28:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:11:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make_save(t_compiler *self)
{
	self->bytecode_fd = open(self->bytecode_fn,
		O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (self->bytecode_fd >= 0)
	{
		if (ft_writeall(self->bytecode_fd,
			self->bytecode_data, self->bytecode_size))
		{
			return (TRUE);
		}
	}
	ft_printf("Can't write output file %s", self->bytecode_fn);
	return (FALSE);
}
