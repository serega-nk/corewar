/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:41:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:14:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static void		signed_reverse(void *addr, size_t size)
{
	unsigned char	*ptr;
	int				value;

	ptr = (unsigned char *)addr;
	value = 1;
	while (size > 0)
	{
		value = (0xff ^ *ptr) + value;
		*ptr = (unsigned char)value;
		value = (value / 0xff) >> 8;
		ptr++;
		size--;
	}
}

t_process		*process_create(t_vm *vm, t_player *player, long pc)
{
	t_process	*self;

	self = (t_process *)ft_xmemalloc(sizeof(t_process));
	self->vm = vm;
	self->player = player;
	self->pc = pc;
	ft_memcpy(self->reg, &player->id, REG_SIZE);
	signed_reverse(self->reg, REG_SIZE);
	self->arguments = vector_create();
	return (self);
}
