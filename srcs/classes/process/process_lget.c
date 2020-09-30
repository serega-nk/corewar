/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:26:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:35:21 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

int		process_lget(t_process *self, t_arg_type type, int value)
{
	int		rel;

	if (type & T_DIR)
		rel = value;
	else if (type & T_IND)
		rel = process_lread(self, value);
	else
		rel = self->reg[value];
	return (rel);
}
