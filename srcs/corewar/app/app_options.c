/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 01:22:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		app_options_usage(t_app *self)
{
	if (self->args->count == 0)
	{
		ft_printf(
			"Usage: %s [-dump nbr_cycles] [[-n number] champion1.cor] ...\n",
			self->name);
		ft_xexit(EXIT_SUCCESS);
	}
}

static void		app_options_nbr_cycles(t_app *self)
{
	char		*ptr;

	if (vector_peek(self->args, 0, (void **)&ptr) &&
		ft_strequ(ptr, "-dump"))
	{
		self->option_dump = TRUE;
		vector_move(self->args, 1);
		if (vector_next(self->args, (void **)&ptr) == FALSE ||
			parse_long(&ptr, &self->nbr_cycles) == FALSE ||
			parse_none(&ptr) == FALSE)
		{
			ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
			ft_xexit(EXIT_FAILURE);
		}
	}
}

static void		app_options_files(t_app *self)
{
	char		*ptr;
	int			num;

	while (vector_next(self->args, (void **)&ptr))
	{
		if (ft_strequ(ptr, "-n"))
		{
			if (vector_next(self->args, (void **)&ptr) == FALSE ||
				parse_int(&ptr, &num) == FALSE ||
				parse_none(&ptr) == FALSE ||
				vector_next(self->args, (void **)&ptr) == FALSE)
			{
				ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
				ft_xexit(EXIT_FAILURE);
			}
			vector_push_back(self->files, ptr);
		}
		else
		{
			vector_push_back(self->files, ptr);
		}	
	}
}

void			app_options(t_app *self)
{
	app_options_usage(self);
	app_options_nbr_cycles(self);
	app_options_files(self);	
}
