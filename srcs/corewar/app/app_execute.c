/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:12:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 17:09:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_execute(t_app *self)
{
	self->arena = arena_create(self->files, self->nbr_cycles);
	if (arena_battle(self->arena) == FALSE)
		self->error = TRUE;
}
