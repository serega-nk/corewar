/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_lldi.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:36:03 by jremarqu         ###   ########.fr       */
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
}
