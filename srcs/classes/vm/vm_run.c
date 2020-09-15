/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:39:03 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 21:37:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	vm_run(t_vm *self)
{
	if (vm_load(self) &&
		vm_loop(self))
	{
		vm_print(self);
		return (TRUE);
	}
	return (FALSE);
}
