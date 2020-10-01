/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 05:07:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			app_options(t_app *self)
{
	app_options_usage(self);
	while (TRUE)
	{
		if (app_options_dump(self) == FALSE &&
			app_options_verbosity(self) == FALSE)
		{
			break ;
		}
	}
	app_options_files(self);
}
