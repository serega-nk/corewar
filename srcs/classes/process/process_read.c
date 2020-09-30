/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:30:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 12:32:28 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

int		process_read(t_process *self, long rel)
{
	int		value;

	vm_read(self->vm, self->pc + rel % IDX_MOD, &value, sizeof(value));
	ft_memrev(&value, sizeof(value));
	return (value);
}
