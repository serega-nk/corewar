/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:30:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 23:34:37 by jremarqu         ###   ########.fr       */
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
