/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:23:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 16:03:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_intro(t_vm *self)
{
	t_player	*player;

	ft_printf("Introducing contestants...\n");
	vector_start(self->players);
	while (vector_next(self->players, (void **)&player))
	{
		ft_printf("* Player %d, weighing %lu bytes, \"%s\" (\"%s\") !\n",
			player->id, player->size, player->name, player->comment);
	}
}
