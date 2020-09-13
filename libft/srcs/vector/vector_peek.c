/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:42:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/13 18:58:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool			vector_peek(t_vector *self, int rel, void **adata)
{
	size_t		pos;

	if (self && adata && self->pos + rel >= 0)
	{
		pos = self->pos + rel;
		if (pos < self->count)
		{
			*adata = self->table[pos];
			return (TRUE);
		}
	}
	return (FALSE);
}
