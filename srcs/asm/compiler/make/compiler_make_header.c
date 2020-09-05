/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:36:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 23:19:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make_header(t_compiler *self)
{
	unsigned int	magic;

	magic = COREWAR_EXEC_MAGIC;
	ft_memcpy_rev(&self->header.magic, &magic, sizeof(self->header.magic));
	ft_strcpy(self->header.prog_name, self->parser->cmd_name);
	ft_memcpy_rev(&self->header.prog_size, &self->prog_size,
		sizeof(self->header.prog_size));
	ft_strcpy(self->header.comment, self->parser->cmd_comment);
	return (TRUE);
}
