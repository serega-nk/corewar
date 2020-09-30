/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:19:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:23:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_write_int(t_vm *self, long pos, int value)
{
	ft_memrev(&value, sizeof(value));
	vm_write(self, pos, &value, sizeof(value));
}
