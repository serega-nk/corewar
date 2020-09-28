/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:52:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 21:50:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_process	*process_clone(t_process *parent)
{
	t_process	*self;

	self = process_create(parent->vm, parent->player, parent->pc);
	ft_memcpy(self->reg, parent->reg, sizeof(parent->reg));
	return (self);
}
