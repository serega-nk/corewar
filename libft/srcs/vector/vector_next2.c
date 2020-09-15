/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_next2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:47:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/14 04:54:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void		*vector_next2(t_vector *self)
{
	void	*data;

	data = NULL;
	vector_next(self, &data);
	return (data);
}
