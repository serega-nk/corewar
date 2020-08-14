/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:47:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 18:54:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool		vector_next(t_vector *self, void **adata)
{
	if (self && adata && self->start < self->count)
	{
		*adata = self->table[self->start++];
		return (TRUE);
	}
	return (FALSE);
}
