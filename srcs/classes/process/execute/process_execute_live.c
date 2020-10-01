/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_live.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 04:39:15 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_live(t_process *self, int v[3])
{
	t_player	*player;

	self->last_live = self->vm->cycles_num;
	self->vm->lives_num++;
	if (vector_get(self->vm->players, -v[0] - 1, (void **)&player))
	{
		self->vm->winner = player;
		ft_printf("A process shows that player %d (%s) is alive\n",
			player->id, player->name);
	}
}
