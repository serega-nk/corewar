/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:42 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 03:56:01 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_add(t_process *self, int v[3])
{
	self->reg[v[2]] = self->reg[v[0]] + self->reg[v[1]];
	self->carry = (self->reg[v[2]] == 0);
	if (TRUE)
	{
		
	}
}
