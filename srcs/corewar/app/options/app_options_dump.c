/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_dump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:09:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 16:40:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
