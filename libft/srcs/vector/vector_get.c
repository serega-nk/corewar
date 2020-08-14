/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:52:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 00:00:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool		vector_get(t_vector *self, size_t index, void **adata)
{
	if (self && adata && index >= 0 && index < self->count)
	{
		*adata = self->table[index];
		return (TRUE);
	}
	return (FALSE);
}
