/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_calc_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:00:05 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 18:05:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

size_t	argument_calc_size(t_argument *self, t_bool dir_ind)
{
	self->size = 0;
	if (self->arg_type & T_REG)
		self->size = NUM_SIZE;
	else if (self->arg_type & T_DIR)
		self->size = (dir_ind ? IND_SIZE : DIR_SIZE);
	else if (self->arg_type & T_IND)
		self->size = IND_SIZE;
	return (self->size);
}
