/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:36:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 00:16:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_make_header(t_compiler *self)
{
	unsigned int	magic;

	magic = COREWAR_EXEC_MAGIC;
	ft_memcpy(&self->header.magic, &magic, sizeof(self->header.magic));
	ft_memrev(&self->header.magic,sizeof(self->header.magic));
	ft_strcpy(self->header.prog_name, self->parser->cmd_name);
	ft_memcpy(&self->header.prog_size, &self->prog_size,
		sizeof(self->header.prog_size));
	ft_memrev(&self->header.prog_size, sizeof(self->header.prog_size));
	ft_strcpy(self->header.comment, self->parser->cmd_comment);
	return (TRUE);
}
