/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:41:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 18:58:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_process	*process_create(t_vm *vm, t_player *player)
{
	t_process	*self;

	self = (t_process *)ft_xmemalloc(sizeof(t_process));
	self->vm = vm;
	self->player = player;
	return (self);
}
