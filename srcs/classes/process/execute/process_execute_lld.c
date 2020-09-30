/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lld.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 02:42:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_lld(t_process *self, int v[3], t_arg_type t[3])
{
	// ft_printf("LLD t[0]=%d,  v[0] = %d, v[1] =  %d, pc =%d\n", t[0], v[0], v[1], self->pc);
	self->reg[v[1]] = process_lget(self, t[0], v[0]);
	self->carry = (self->reg[v[1]] == 0);
}
