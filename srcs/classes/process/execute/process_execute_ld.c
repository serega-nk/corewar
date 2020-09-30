/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:57 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:38:53 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		process_execute_ld(t_process *self, int v[3], t_arg_type t[3])
{
	self->reg[v[1]] = process_get(self, t[0], v[0]);
	self->carry = (self->reg[v[1]] == 0);
}
