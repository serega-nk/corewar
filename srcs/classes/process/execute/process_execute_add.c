/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 12:42:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_add(t_process *self, int v[3])
{
	self->reg[v[2]] = self->reg[v[0]] + self->reg[v[1]];
	self->carry = (self->reg[v[2]] == 0);
}
