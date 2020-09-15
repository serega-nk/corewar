/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:41:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 16:45:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_arena		*arena_create(t_vector *files, long nbr_cycles)
{
	t_arena	*self;

	self = (t_arena *)ft_xmemalloc(sizeof(t_arena));
	self->files = files;
	self->nbr_cycles = nbr_cycles;
	return (self);
}
