/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:30:04 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 12:34:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_set(t_vector *self, size_t index, void *data)
{
	if (self)
	{
		if (self->count <= index)
		{
			self->count = index + 1;
			if (self->capacity < self->count)
				vector_resize(self, self->count);
		}
		self->table[index] = data;
	}
}
