/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:11:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/14 06:36:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		app_init(t_app *self, int argc, char *argv[])
{
	int		index;

	ft_bzero(self, sizeof(t_app));
	ft_on_xexit(&app_free, self);
	self->name = argv[0];
	self->args = vector_create();
	index = 1;
	while (index < argc)
	{
		vector_push_back(self->args, argv[index]);
		index++;
	}
	vector_start(self->args);
}
