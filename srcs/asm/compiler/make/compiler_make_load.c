/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:27:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 21:05:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	get_size(int fd)
{
	off_t		curr;
	size_t		size;

	curr = lseek(fd, 0, SEEK_CUR);
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, curr, SEEK_SET);
	return (size);
}

static t_bool	readall(int fd, char *data, size_t size)
{
	size_t		used;
	ssize_t		n;

	used = 0;
	while (used < size)
	{
		n = read(fd, data + used, size - used);
		if (n <= 0)
			break ;
		used += n;
	}
	return (used == size);
}

t_bool			compiler_make_load(t_compiler *self)
{
	self->source_fd = open(self->sourcefile, O_RDONLY);
	if (self->source_fd >= 0)
	{
		self->source_size = get_size(self->source_fd);
		self->source_data = ft_xmalloc(self->source_size);
		if (readall(self->source_fd, self->source_data, self->source_size))
			return (TRUE);
	}
	ft_printf_fd(STDERR_FILENO, "Can't read source file %s\n",
		self->sourcefile);
	return (FALSE);
}
