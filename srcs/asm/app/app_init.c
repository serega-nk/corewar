/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:19:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/02 21:51:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	app_init(t_app *self, int argc, char *argv[])
{
	ft_bzero(self, sizeof(t_app));
	ft_on_xexit(&app_free, self);
	self->argc = argc;
	self->argv = argv;
}
