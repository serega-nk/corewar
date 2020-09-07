/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:30:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	app_execute(t_app *self)
{
	t_bool	multi;

	multi = self->argc != 1;
	while (self->argc > 0)
	{
		self->compiler = compiler_create(*self->argv);
		if (compiler_make(self->compiler, multi))
		{
			if (self->option_t)
				compiler_print_tokens(self->compiler);
			if (self->option_l)
				compiler_print_labels(self->compiler);
			if (self->option_i)
				compiler_print_instructions(self->compiler);
			if (self->option_b)
				compiler_print_bytecode(self->compiler);
		}
		else
			self->error = TRUE;
		compiler_destroy(&self->compiler);
		self->argv++;
		self->argc--;
		if (self->argc > 0)
			ft_printf("\n");
	}
}
