/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:30:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/10 19:29:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static void		app_execute_print(t_app *self)
{
	char	*line;

	vector_start(self->decompiler->lines);
	while (vector_next(self->decompiler->lines, (void **)&line))
	{
		ft_printf("%s", line);
	}
}

void			app_execute(t_app *self)
{
	if (self->argc != 1)
	{
		ft_printf_fd(STDERR_FILENO, "Invalid number of arguments\n");
		ft_xexit(EXIT_FAILURE);
	}
	self->decompiler = decompiler_create(self->argv[0]);
	if (decompiler_make(self->decompiler) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO,
			"{red}%s{eoc}\n", self->decompiler->error_message);
		ft_xexit(EXIT_FAILURE);
	}
	app_execute_print(self);
	decompiler_destroy(&self->decompiler);
}
