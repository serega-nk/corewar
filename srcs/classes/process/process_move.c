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

void	process_move(t_process *self, int rel)
{
	self->pc = (self->pc + rel) % MEM_SIZE;
}
