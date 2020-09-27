/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:22:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/17 02:37:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"


static t_bool	load(t_vm *self, char *path, int index, int count)
{
	int				fd;
	t_header		header;
	unsigned int	magic;
	unsigned int	prog_size;
	t_player		*player;
	t_process		*process;
	size_t			size;
	
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR READ %s\n", path);
		ft_xexit(EXIT_FAILURE);		
	}
	size = ft_get_size(fd);
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
	prog_size = header.prog_size;
	ft_memrev(&prog_size, sizeof(header.prog_size));
	if (prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR CHAMP SIZE %lu > %lu\n", prog_size, CHAMP_MAX_SIZE);
		ft_xexit(EXIT_FAILURE);			
	}
	if (size != sizeof(header) + prog_size)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR FILE SIZE\n");
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
	// TODO:
	// ft_printf("#%s\n", header.prog_name);
	player = player_create(index + 1, header.prog_name, header.comment);
	player->prog_size = prog_size;
	vector_push_back(self->players, player);
	process = process_create(self, player, index * (MEM_SIZE / count));
	list_push_front(self->processes, process);
	if (process->curr + prog_size > MEM_SIZE)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR process->curr + prog_size > MEM_SIZE\n");
		ft_xexit(EXIT_FAILURE);
	}
	if (ft_readall(fd, self->mem + process->curr, prog_size) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR READ BYTECODE\n");
		ft_xexit(EXIT_FAILURE);
	}
	ft_close(&fd);	
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
