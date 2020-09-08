/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make_header.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:13:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disclasses.h"

t_bool	decompiler_make_header(t_decompiler *self)
{
	int		magic;
	int		prog_size;

	if (self->bytecode_size < sizeof(t_header))
	{
		ft_printf_fd(STDERR_FILENO, "ERROR SIZE");
		return (FALSE);
	}
	
	ft_memcpy(&self->header, self->bytecode_data, sizeof(t_header));
	self->bytecode_pos = sizeof(t_header);
	
	ft_memcpy_rev(&magic, &self->header.magic, sizeof(magic));	
	if (magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR COREWAR_EXEC_MAGIC");
		return (FALSE);
	}
	
	if (self->header.prog_name[PROG_NAME_LENGTH] != '\0')
	{
		ft_printf_fd(STDERR_FILENO, "ERROR PROG_NAME");
		return (FALSE);
	}
	
	if (self->header.comment[COMMENT_LENGTH] != '\0')
	{
		ft_printf_fd(STDERR_FILENO, "ERROR COMMENT");
		return (FALSE);
	}

	ft_memcpy_rev(&prog_size, &self->header.prog_size, sizeof(prog_size));
	if (prog_size != (int)(self->bytecode_size - self->bytecode_pos))
	{
		ft_printf_fd(STDERR_FILENO, "ERROR PROG SIZE");
		return (FALSE);
	}
	return (TRUE);
}
