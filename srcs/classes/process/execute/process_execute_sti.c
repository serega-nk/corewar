/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_sti.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:59:00 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_execute_sti(t_process *self, int v[3], t_arg_type t[3])
{
	int		data;
	int		rel1;
	int		rel2;

	data = process_get(self, t[0], v[0]);
	rel1 = process_get(self, t[1], v[1]);
	rel2 = process_get(self, t[2], v[2]);
	process_write(self, rel1 + rel2, data);
}
