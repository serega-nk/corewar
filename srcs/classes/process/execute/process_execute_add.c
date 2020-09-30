/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 09:40:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_add(t_process *self)
{
	self->reg[self->args[2]] = \
		self->reg[self->args[0]] + self->reg[self->args[1]];
	self->carry = (self->reg[self->args[2]] == 0);
}
