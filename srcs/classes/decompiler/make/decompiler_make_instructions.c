/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:13:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 01:49:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool	decompiler_eof(t_decompiler *self)
{
	return (self->bytecode_pos >= self->bytecode_size);
}

// char	decompiler_peak(t_decompiler *self, int rel)
// {
// 	return (self->bytecode_pos >= self->bytecode_size);
// }


// t_bool	decompiler_make_instruction(t_decompiler *self)
// {

// }

t_bool	decompiler_make_instructions(t_decompiler *self)
{
	while (decompiler_eof(self) == FALSE)
	{
		// decompiler_make_instruction();

		// if decompiler_make_instruction(self)

		return (TRUE);
	}
	return (TRUE);
}
