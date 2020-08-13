/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:43:26 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 23:47:57 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_destroy(t_vector **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)&(*aself)->table);
		ft_memdel((void **)aself);
	}
}
