/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_live.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:25:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_live(t_process *self)
{
	t_player	*player;

	self->last_live = self->vm->cycles_num;
	self->vm->lives_num++;
	if (vector_get(self->vm->players, -self->args[0], (void **)&player))
	{
		self->vm->winner = player;
		player->lives_num++;
		ft_printf("A process shows that player %d (%s) is alive",
			player->id, player->name);
	}
}
