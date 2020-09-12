/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:11:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 12:11:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_init(t_app *self, int argc, char *argv[])
{
	ft_bzero(self, sizeof(t_app));
	ft_on_xexit(&app_free, self);
	self->argc = argc;
	self->argv = argv;
}
