/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_or.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:43:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:30:53 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		process_execute_or(t_process *self, int v[3], t_arg_type t[3])
{
	int		a;
	int		b;

	a = process_get(self, t[0], v[0]);
	b = process_get(self, t[1], v[1]);
	self->reg[v[2]] = a | b;
	self->carry = (self->reg[v[2]] == 0);
}
