/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:09:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:27:00 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_move(t_process *self)
{
	//ft_printf("## MOVE %p, %ld\n", self, self->step);
	self->pc = (self->pc + self->step) % MEM_SIZE;
	self->step = 0;
}
