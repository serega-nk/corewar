/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:47:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/13 18:46:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool		vector_next(t_vector *self, void **adata)
{
	if (vector_peek(self, 0, adata))
	{
		vector_move(self, 1);
		return (TRUE);
	}
	return (FALSE);
}
