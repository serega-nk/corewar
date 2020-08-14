/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:44:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 00:01:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_create(void)
{
	t_vector	*self;

	self = (t_vector *)ft_xmemalloc(sizeof(t_vector));
	self->capacity = 2;
	self->table = (void **)ft_xmemalloc(self->capacity * sizeof(void *));
	return (self);
}
