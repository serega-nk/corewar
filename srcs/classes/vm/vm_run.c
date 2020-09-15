/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzei <wzei@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:39:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 21:12:57 by wzei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	vm_run(t_vm *self)
{
	int		index;
	char	*path;
	
	// Serega
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

	if (vm_loop(self) == FALSE)
		return (FALSE);
	return (TRUE);
}
