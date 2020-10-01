/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_verbosity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 05:03:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 05:11:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_bool	app_options_verbosity(t_app *self)
{
	char		*ptr;
	long		value;

	if (self->argc >= 2 && ft_strequ(self->argv[0], "-v"))
	{
		ptr = self->argv[1];
		if (parse_long(&ptr, &value) &&
			parse_none(&ptr))
		{
			self->argc -= 2;
			self->argv += 2;
			self->verbosity = value;
			return (TRUE);
		}
		ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
		ft_xexit(EXIT_FAILURE);
	}
	return (FALSE);
}
