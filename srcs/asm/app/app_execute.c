/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:52 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 23:08:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		app_execute_success(t_app *self)
{
	if (self->success > 0)
		ft_printf("\n");
	self->success += 1;
	if (self->multi)
	{
		ft_printf("Compile file: %s\n", self->compiler->source_fn);
		ft_printf("┗━━ ");
	}
	ft_printf("{green}Writing output program to %s{eoc}\n",
		self->compiler->bytecode_fn);
	if (self->option_t)
		compiler_print_tokens(self->compiler);
	if (self->option_l)
		compiler_print_labels(self->compiler);
	if (self->option_i)
		compiler_print_instructions(self->compiler);
	if (self->option_b)
		compiler_print_bytecode(self->compiler);
}

static void		app_execute_errors(t_app *self)
{
	if (self->errors > 0)
		ft_printf_fd(STDERR_FILENO, "\n");
	self->errors += 1;
	if (self->multi)
	{
		ft_printf_fd(STDERR_FILENO, "Error compile file: %s\n",
			self->compiler->source_fn);
		ft_printf_fd(STDERR_FILENO, "┗━━ ");
	}
	ft_printf_fd(STDERR_FILENO, "{red}%s{eoc}\n",
		self->compiler->error_message);
}

void			app_execute(t_app *self)
{
	while (self->argc > 0)
	{
		self->compiler = compiler_create(*self->argv);
		if (compiler_make(self->compiler))
			app_execute_success(self);
		else
			app_execute_errors(self);
		compiler_destroy(&self->compiler);
		self->argv++;
		self->argc--;
	}
}
