/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:16:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 21:17:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	compiler_make_header(t_compiler *self)
{
	self->header.magic = COREWAR_EXEC_MAGIC;
	ft_strncpy(self->header.prog_name, self->parser->command_name,
		PROG_NAME_LENGTH);
	ft_strncpy(self->header.comment, self->parser->command_comment,
		COMMENT_LENGTH);
}
