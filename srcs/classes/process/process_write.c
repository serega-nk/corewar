/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 23:40:46 by jremarqu          #+#    #+#             */
/*   Updated: 2020/10/01 00:07:51 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void 	process_write(t_process *self, long rel, int value)
{
	ft_memrev(&value, sizeof(value));
	vm_write(self->vm, self->pc + rel % IDX_MOD, &value, sizeof(value));
}
