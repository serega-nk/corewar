/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 12:37:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		process_execute_ld(t_process *self, int v[3], t_arg_type t[3])
{
	self->reg[v[1]] = process_get(self, t[0], v[0]);
	self->carry = (self->reg[v[1]] == 0);
}
