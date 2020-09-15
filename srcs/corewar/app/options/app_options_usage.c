/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_usage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:06:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 16:52:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_options_usage(t_app *self)
{
	if (self->argc == 0)
	{
		ft_printf(
			"Usage: %s [-dump nbr_cycles] [[-n number] champion1.cor] ...\n",
			self->name);
		ft_xexit(EXIT_SUCCESS);
	}
}
