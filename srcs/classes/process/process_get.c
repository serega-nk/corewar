/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:26:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 12:47:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

int		process_get(t_process *self, t_arg_type type, int value)
{
	int		rel;

	if (type & T_DIR)
		rel = value;
	else if (type & T_IND)
		rel = process_read(self, value);
	else
		rel = self->reg[value];
	return (rel);
}
