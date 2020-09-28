/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:22:49 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 19:45:06 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void			vm_load(t_vm *self)
{
	char		*path;
	t_player	*player;

	vector_start(self->files);
	while (vector_next(self->files, (void **)&path))
	{
		player = player_create(self->players->count + 1);
		vector_push_back(self->players, player);
		if (player_load(player, path) == FALSE)
		{
			ft_printf_fd(STDERR_FILENO, "{red}%s{eoc}\n",
				player->error_message);
			ft_xexit(EXIT_FAILURE);
		}
		self->winner = player;
	}
}
