/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_bytecodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/02 23:29:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	app_bytecodes(t_app *self)
{
	while (self->argc > 0)
	{
		self->compiler = compiler_create(*self->argv);
		if (compiler_make(self->compiler))
		{
			if (self->option_t)
				compiler_output_tokens(self->compiler);
			if (self->option_l)
				compiler_output_labels(self->compiler);
			if (self->option_i)
				compiler_output_instructions(self->compiler);
			if (self->option_a)
				compiler_output_annotated(self->compiler);
		}
		else
		{
			self->error = TRUE;
		}
		compiler_destroy(&self->compiler);
		self->argv++;
		self->argc--;
	}
}
