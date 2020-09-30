/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_read_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:29:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:23:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

int		vm_read_int(t_vm *self, long pos)
{
	int		value;

	vm_read(self, pos, &value, sizeof(value));
	ft_memrev(&value, sizeof(value));
	return (value);
}
