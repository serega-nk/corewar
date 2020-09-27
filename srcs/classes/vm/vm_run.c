/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:39:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 21:37:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

// Introducing contestants...
// * Player 1, weighing 22 bytes, "Batman" ("This city needs me") !
// * Player 2, weighing 22 bytes, "Batman" ("This city needs me") !
// * Player 3, weighing 200 bytes, "error_bot_name not found" ("") !

t_bool	vm_intro(t_vm *self)
{
	t_player	*player;

	ft_printf("Introducing contestants...\n");
	vector_start(self->players);
	while (vector_next(self->players, (void **)&player))
	{
		ft_printf("* Player %d, weighing %lu bytes, \"%s\" (\"%s\") !\n",
			player->id, player->prog_size, player->name, player->comment);
	}
	return (TRUE);
}

t_bool	vm_run(t_vm *self)
{
	if (vm_load(self) &&
		vm_intro(self) &&
		vm_loop(self))
	{
		// vm_print(self);
		return (TRUE);
	}
	return (FALSE);
}
