/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:40:46 by jremarqu          #+#    #+#             */
/*   Updated: 2020/10/01 01:14:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_write(t_process *self, long rel, int value)
{
	ft_memrev(&value, sizeof(value));
	vm_write(self->vm, self->pc + rel % IDX_MOD, &value, sizeof(value));
}
