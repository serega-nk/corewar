/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 03:27:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 09:03:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_instruction		*instruction_create(void)
{
	t_instruction	*self;

	self = (t_instruction *)ft_xmemalloc(sizeof(t_instruction));
	self->arguments = vector_create();
	return (self);
}
