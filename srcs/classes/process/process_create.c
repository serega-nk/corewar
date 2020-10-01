/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:41:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 04:24:25 by jremarqu         ###   ########.fr       */
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
	self->id = ++self->vm->process_nbr;
	return (self);
}
