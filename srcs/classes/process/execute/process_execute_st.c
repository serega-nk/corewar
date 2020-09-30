/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_st.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 12:44:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_st(t_process *self, int v[3], t_arg_type t[3])
{
	int		val;
	long	rel;

	if (t[1] & T_IND)
	{
		val = self->reg[v[0]];
		rel = v[1] % IDX_MOD;
		vm_write_int(self->vm, self->pc + rel, val);
	}
	else
	{
		self->reg[v[1]] = self->reg[v[0]];
	}
}
