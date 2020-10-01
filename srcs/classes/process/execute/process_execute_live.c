/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_live.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:24 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 17:56:38 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   live
**
** OPCODE
**
**   0x01
**
** 42 SUBJECT REFERENCE
**
**   live: The instruction that allows a process to stay alive. It can also
**   record that the player whose number is the argument is indeed alive.
**   No argument’s coding byte, opcode 0x01. Oh and its only argument is
**   on 4 bytes.
**
** EPITECH SUBJECT REFERENCE
**
**   Followed by 4 bytes representing the player name. This instruction
**   indicates that the player is alive. (No parameter encoding byte).
**
** USAGE EXAMPLE
**
**   live:	live \%1
**
**   {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0}
*/

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
