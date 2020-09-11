/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_make_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:21:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 00:18:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_make_header(t_deparser *self)
{
	int		magic;
	int		prog_size;

	if (deparser_next(self, &self->header, sizeof(t_header)) == FALSE)
		return (deparser_error(self, "ERROR HEADER SIZE"));
	ft_memcpy(&magic, &self->header.magic, sizeof(magic));
	ft_memrev(&magic, sizeof(magic));
	if (magic != COREWAR_EXEC_MAGIC)
		return (deparser_error(self, "ERROR COREWAR_EXEC_MAGIC"));
	if (self->header.prog_name[PROG_NAME_LENGTH] != '\0')
		return (deparser_error(self, "ERROR PROG_NAME"));
	if (self->header.comment[COMMENT_LENGTH] != '\0')
		return (deparser_error(self, "ERROR COMMENT"));
	ft_memcpy(&prog_size, &self->header.prog_size, sizeof(prog_size));
	ft_memrev(&prog_size, sizeof(prog_size));
	if (prog_size != (int)self->size - (int)self->pos)
		return (deparser_error(self, "ERROR PROG_SIZE"));
	return (TRUE);
}
