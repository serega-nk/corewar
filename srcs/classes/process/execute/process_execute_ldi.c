/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_ldi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 11:22:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 02:38:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		process_execute_ldi(t_process *self, int v[3], t_arg_type t[3])
{
	int		rel0;
	int		rel1;

	rel0 = process_get(self, t[0], v[0]);
	rel1 = process_get(self, t[1], v[1]);
	self->reg[v[2]] = process_read(self, rel0 + rel1);
	self->carry = (self->reg[v[2]] == 0);
}
