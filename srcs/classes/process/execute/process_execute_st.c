/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_st.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:06:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_st(t_process *self)
{
	int		val;
	long	rel;

	if (self->arg_types[1] & T_IND)
	{
		val = self->reg[self->args[0]];
		rel = self->args[1] % IDX_MOD;
		ft_printf("ST rel = %d, val = %d\n", rel, val);
		vm_write_int(self->vm, self->pc + rel, val);
	}
	else
	{
		self->reg[self->args[1]] = self->reg[self->args[0]];
	}
}
