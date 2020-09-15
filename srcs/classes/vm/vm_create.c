/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:38:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 18:38:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_vm	*vm_create(t_vector *files, long nbr_cycles)
{
	t_vm	*self;

	self = (t_vm *)ft_xmemalloc(sizeof(t_vm));
	self->files = files;
	self->nbr_cycles = nbr_cycles;
	return (self);
}
