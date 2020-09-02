/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_bytecodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/02 22:33:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			app_bytecodes(t_app *self)
{
	t_compiler	*compiler;

	while (self->argc > 0)
	{
		compiler = compiler_create(*self->argv);
		if (compiler_make(compiler))
		{
			if (self->option_t)
				compiler_output_tokens(compiler);
			if (self->option_l)
				compiler_output_labels(compiler);
			if (self->option_i)
				compiler_output_instructions(compiler);
			if (self->option_a)
				compiler_output_annotated(compiler);
		}
		else
		{
			self->error = TRUE;
		}
		compiler_destroy(&compiler);
		self->argv++;
		self->argc--;
	}
}
