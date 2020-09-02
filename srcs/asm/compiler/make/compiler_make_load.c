/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:27:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 00:11:44 by bconchit         ###   ########.fr       */
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

static size_t	readall(int fd, char *data, size_t size)
{
	size_t		used;
	ssize_t		n;

	used = 0;
	while (used < size)
	{
		n = read(fd, data + used, size - used);
		if (n == 0)
			break ;
		used += n;
	}
	return (used);
}

t_bool			compiler_make_load(t_compiler *self)
{
	int			fd;
	size_t		ret;

	fd = open(self->sourcefile, O_RDONLY);
	if (fd < 0)
	{
		ft_printf_fd(STDERR_FILENO, "Can't read source file %s\n",
			self->sourcefile);
		return (FALSE);
	}
	self->source_size = get_size(fd);
	self->source_data = ft_xmalloc(self->source_size);
	ret = readall(fd, self->source_data, self->source_size);
	close(fd);
	if (ret != self->source_size)
	{
		ft_printf_fd(STDERR_FILENO, "Can't read source file %s" \
			", only %lu bytes out of %lu were read",
			self->sourcefile, ret, self->source_size);
		return (FALSE);
	}
	return (TRUE);
}
