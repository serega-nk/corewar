/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:52:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 01:36:50 by bconchit         ###   ########.fr       */
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
	return (self);
}
