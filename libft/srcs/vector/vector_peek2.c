/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_peek2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:42:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/14 04:52:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	*vector_peek2(t_vector *self, int rel)
{
	void	*data;

	data = NULL;
	vector_peek(self, rel, &data);
	return (data);
}
