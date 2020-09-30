/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:30:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:28:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_bool	player_load_header(t_player *self, t_header *header)
{
	size_t		size;

	size = ft_get_size(self->fd);
	if (ft_readall(self->fd, (char *)header, sizeof(t_header)) == FALSE)
		return (player_error(self, "ERROR READ HEADER"));
	ft_memrev(&header->magic, sizeof(header->magic));
	ft_memrev(&header->prog_size, sizeof(header->prog_size));
	if (header->magic != COREWAR_EXEC_MAGIC)
		return (player_error(self, "ERROR COREWAR_EXEC_MAGIC"));
	if (header->prog_size > CHAMP_MAX_SIZE)
	{
		return (player_errorf(self, ft_xprintf("ERROR CHAMP SIZE %lu > %lu\n",
			header->prog_size, CHAMP_MAX_SIZE)));
	}
	if (header->prog_name[PROG_NAME_LENGTH] != '\0')
		return (player_error(self, "ERROR PROG_NAME"));
	if (header->comment[COMMENT_LENGTH] != '\0')
		return (player_error(self, "ERROR COMMENT"));
	if (sizeof(t_header) + header->prog_size != size)
		return (player_error(self, "ERROR FILE SIZE"));
	return (TRUE);
}

t_bool			player_load(t_player *self, char *path)
{
	t_header	hdr;

	self->fd = open(path, O_RDONLY);
	if (self->fd < 0)
		return (player_errorf(self, ft_xprintf("ERROR READ %s", path)));
	if (player_load_header(self, &hdr) == FALSE)
		return (FALSE);
	self->name = ft_xstrdup(hdr.prog_name);
	self->comment = ft_xstrdup(hdr.comment);
	self->size = hdr.prog_size;
	self->data = ft_xmalloc(self->size);
	if (ft_readall(self->fd, self->data, self->size) == FALSE)
		return (player_error(self, "ERROR READ BYTECODE"));
	ft_close(&self->fd);
	return (TRUE);
}
