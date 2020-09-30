/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_st.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:23:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 00:03:27 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_st(t_process *self, int v[3], t_arg_type t[3])
{
	if (t[1] & T_IND)
		process_write(self, v[1], self->reg[v[0]]);
	else
		self->reg[v[1]] = self->reg[v[0]];
}
