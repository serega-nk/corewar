/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:48:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 18:25:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_resize(t_vector *self, size_t capacity)
{
	void	*table;

	if (self && self->capacity < capacity)
	{
		table = (void **)ft_xmemalloc(capacity * sizeof(void *));
		ft_memcpy(table, self->table, self->capacity * sizeof(void *));
		ft_memdel((void **)&self->table);
		self->capacity = capacity;
		self->table = table;
	}
}
