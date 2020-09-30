/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:41:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:22:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_process		*process_create(t_vm *vm, t_player *player, long pc)
{
	t_process	*self;

	self = (t_process *)ft_xmemalloc(sizeof(t_process));
	self->vm = vm;
	self->player = player;
	self->pc = pc;
	self->reg[1] = -player->id;
	self->arguments = vector_create();
	return (self);
}
