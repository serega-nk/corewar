/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:09:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 03:28:35 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	check_to_error_max_plyrs(t_app *self) is the special func
**	for app_optioms_files wich we use in
**	static void		app_options_files_after(t_app *self) func
*/

void	check_to_error_max_plyrs(t_app *self)
{
	ft_printf_fd(STDERR_FILENO,
		"Wrong number of players = %ld (MAX_PLAYERS %ld)\n",
		self->files->count, MAX_PLAYERS);
	ft_xexit(EXIT_FAILURE);
}

void	app_options_dump(t_app *self)
{
	char		*ptr;

	if (self->argc >= 2 && ft_strequ(self->argv[0], "-dump"))
	{
		ptr = self->argv[1];
		if (parse_long(&ptr, &self->nbr_cycles) &&
			parse_none(&ptr))
		{
			self->argc -= 2;
			self->argv += 2;
			return ;
		}
		ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
		ft_xexit(EXIT_FAILURE);
	}
}
