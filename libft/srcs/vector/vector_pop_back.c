/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:25:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 18:27:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool	vector_pop_back(t_vector *self, void **adata)
{
	if (self && self->count > 0)
	{
		*adata = self->table[--self->count];
		return (TRUE);
	}
	return (FALSE);
}
