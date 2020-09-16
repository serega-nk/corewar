/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:22:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/16 16:26:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"


static t_bool	load(t_vm *self, char *path, int index, int count)
{
	int				fd;
	t_header		header;
	unsigned int	magic;
	unsigned int	size;
	t_player		*player;
	t_process		*process;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR READ %s\n", path);
		ft_xexit(EXIT_FAILURE);		
	}
	if (ft_readall(fd, (char *)&header, sizeof(header)) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR READ HEADER\n");
		ft_xexit(EXIT_FAILURE);
	}
	magic = header.magic;
	ft_memrev(&magic, sizeof(magic));
	if (magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR COREWAR_EXEC_MAGIC\n");
		ft_xexit(EXIT_FAILURE);
	}
	size = header.prog_size;
	ft_memrev(&size, sizeof(header.prog_size));
	if (size > CHAMP_MAX_SIZE)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR CHAMP SIZE %lu > %lu\n", size, CHAMP_MAX_SIZE);
		ft_xexit(EXIT_FAILURE);			
	}
	if (header.prog_name[PROG_NAME_LENGTH] != '\0')
	{
		ft_printf_fd(STDERR_FILENO, "ERROR PROG_NAME\n");
		ft_xexit(EXIT_FAILURE);
	}
	if (header.comment[COMMENT_LENGTH] != '\0')
	{
		ft_printf_fd(STDERR_FILENO, "ERROR COMMENT\n");
		ft_xexit(EXIT_FAILURE);
	}
	player = player_create(index, header.prog_name, header.comment);
	vector_push_back(self->players, player);
	process = process_create(self, player, index * (MEM_SIZE / count));
	vector_push_back(self->players, player);
	if (ft_readall(fd, self->mem + process->curr, size) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR READ BYTECODE\n");
		ft_xexit(EXIT_FAILURE);
	}		
	return (TRUE);
}

t_bool			vm_load(t_vm *self)
{
	int			index;
	char		*path;

	index = 0;
	vector_start(self->files);
	while (vector_next(self->files, (void **)&path))
	{
		if (load(self, path, index, self->files->count) == FALSE)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
