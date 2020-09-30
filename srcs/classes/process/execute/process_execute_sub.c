/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:00:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 09:00:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_sub(t_process *self)
{
	self->reg[self->args[2]] = \
		self->reg[self->args[0]] - self->reg[self->args[1]];
	self->carry = (self->reg[self->args[2]] == 0);
}
