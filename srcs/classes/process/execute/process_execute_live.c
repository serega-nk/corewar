/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_live.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 00:13:22 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_live(t_process *self, int v[3])
{
	t_player	*player;

	self->last_live = self->vm->cycles_num;
	self->vm->lives_num++;
	if (vector_get(self->vm->players, -v[0], (void **)&player))
	{
		self->vm->winner = player;
		// player->lives_num++;
		// ft_printf("A process shows that player %d (%s) is alive\n",
		// 	player->id, player->name);
	}
}
