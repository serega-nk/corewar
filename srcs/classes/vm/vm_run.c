/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:39:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 19:16:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	vm_run(t_vm *self)
{
	int		index;
	char	*path;
	
	ft_printf("nbr_cycles = %d\n", self->nbr_cycles);	
	index = 0;
	vector_start(self->files);
	while (vector_next(self->files, (void **)&path))
	{
		ft_printf("#%d == %s\n", index, path);
		index++;
	}
	///
	t_player	*player;
		
	player = player_create("zorg", "");
	vector_push_back(self->players, player);
	player = player_create("test", "");
	vector_push_back(self->players, player);

	return (TRUE);
}
