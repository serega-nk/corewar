/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:29:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 18:34:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_push_back(t_vector *self, void *data)
{
	if (self)
	{
		if (self->count == self->capacity)
			vector_resize(self, self->capacity * 2);
		self->table[self->count++] = data;
	}
}
