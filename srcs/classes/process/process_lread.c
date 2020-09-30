/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:30:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 02:13:02 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

int		process_lread(t_process *self, long rel)
{
	short	value;

	vm_read(self->vm, self->pc + rel, &value, sizeof(value));
	ft_memrev(&value, sizeof(value));	
	return (value);
}
