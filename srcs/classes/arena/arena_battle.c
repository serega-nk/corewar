/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_battle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:48:44 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 17:10:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	arena_battle(t_arena *self)
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
	return (TRUE);
}
