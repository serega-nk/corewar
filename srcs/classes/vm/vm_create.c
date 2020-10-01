/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:38:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 04:46:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_vm	*vm_create(t_vector *files, long nbr_cycles, t_verbosity verbosity)
{
	t_vm	*self;

	self = (t_vm *)ft_xmemalloc(sizeof(t_vm));
	self->files = files;
	self->nbr_cycles = nbr_cycles;
	self->verbosity = verbosity;
	self->players = vector_create();
	self->processes = list_create();
	self->fork_processes = list_create();
	self->cycles_to_die = CYCLE_TO_DIE;	
	return (self);
}
