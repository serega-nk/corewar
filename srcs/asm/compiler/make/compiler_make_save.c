/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_save.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:28:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 18:15:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	writeall(int fd, char *data, size_t size)
{
	size_t		used;
	ssize_t		n;

	used = 0;
	while (used < size)
	{
		n = write(fd, data + used, size - used);
		if (n <= 0)
			break ;
		used += n;
	}
	return (used == size);
}

static t_bool	save(t_compiler *self)
{
	t_instruction	*instruction;

	if (writeall(
		self->output_fd, (char *)&self->header, sizeof(self->header)) == FALSE)
	{
		return (FALSE);
	}
	vector_start(self->parser->instructions);
	while (vector_next(self->parser->instructions, (void **)&instruction))
	{
		if (writeall(
			self->output_fd, instruction->bytecode, instruction->size) == FALSE)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

t_bool			compiler_make_save(t_compiler *self)
{
	self->output_fd = open(self->outputfile,
		O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (self->output_fd >= 0)
	{
		if (save(self))
			return (TRUE);
	}
	ft_printf_fd(STDERR_FILENO, "Can't write output file %s\n",
		self->outputfile);
	return (FALSE);
}
