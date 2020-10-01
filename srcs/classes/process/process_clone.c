/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:52:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 04:24:35 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_process	*process_clone(t_process *parent, long pc)
{
	t_process	*self;

	self = (t_process *)ft_xmemalloc(sizeof(t_process));
	ft_memcpy(self, parent, sizeof(t_process));
	self->pc = pc;
	self->step = 0;
	self->arguments = vector_create();
	self->id = ++self->vm->process_nbr;
	return (self);
}
