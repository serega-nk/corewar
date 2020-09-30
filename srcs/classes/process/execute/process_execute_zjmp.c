/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_zjmp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:43:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:32:04 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_zjmp(t_process *self, int v[3])
{
	if (self->carry)
	{
		self->step = v[0] % IDX_MOD;
	}
}
