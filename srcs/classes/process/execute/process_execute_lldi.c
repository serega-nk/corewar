/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lldi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 06:00:00 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		process_execute_lldi(t_process *self, int v[3], t_arg_type t[3])
{
	int		rel0;
	int		rel1;

	rel0 = process_lget(self, t[0], v[0]);
	rel1 = process_lget(self, t[1], v[1]);
	self->reg[v[2]] = process_lread(self, rel0 + rel1);
	self->carry = (self->reg[v[2]] == 0);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
	{
		ft_printf("Process %4d | lldi %d %d r%d\n", self->id, rel0, rel1, v[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
		rel0, rel1, rel0 + rel1, self->pc + rel0 + rel1);
	}
}
