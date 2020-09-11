/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:15:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 00:30:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool	decompiler_make_lines(t_decompiler *self)
{
	t_instruction	*instruction;

	vector_push_back(self->lines, ft_xprintf("#\n"));
	vector_push_back(self->lines, ft_xprintf("# DISASM %s\n",
		self->bytecode_fn));
	vector_push_back(self->lines, ft_xprintf("#\n"));
	vector_push_back(self->lines, 
		ft_xprintf(".name \"%s\"\n", self->deparser->header.prog_name));
	vector_push_back(self->lines, 
		ft_xprintf(".comment \"%s\"\n", self->deparser->header.comment));
	vector_push_back(self->lines, ft_xprintf("\n"));
	vector_start(self->deparser->instructions);
	while (vector_next(self->deparser->instructions, (void **)&instruction))
	{
		vector_push_back(self->lines, 
			ft_xprintf("%s\n", instruction_sourcecode(instruction)));
	}
	return (TRUE);
}
