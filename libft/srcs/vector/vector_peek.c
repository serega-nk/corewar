/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:42:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/14 04:44:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool			vector_peek(t_vector *self, int rel, void **adata)
{
	ssize_t		pos;

	if (self && adata)
	{
		pos = (ssize_t)self->pos + rel;
		if (pos >= 0 && pos < (ssize_t)self->count)
		{
			*adata = self->table[pos];
			return (TRUE);
		}
	}
	return (FALSE);
}
