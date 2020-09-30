/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:52:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:25:56 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_process	*process_clone(t_process *parent, long pc)
{
	t_process	*self;

	self = process_create(parent->vm, parent->player, pc);
	ft_memcpy(self->reg, parent->reg, sizeof(parent->reg));
	return (self);
}
