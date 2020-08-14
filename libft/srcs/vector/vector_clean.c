/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:44:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/14 18:53:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_clean(t_vector *self, void (*delf)())
{
	void	*data;

	while (vector_pop_back(self, &data))
	{
		if (delf)
			(*delf)(&data);
	}
}
