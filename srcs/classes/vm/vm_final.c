/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_final.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:03:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 19:17:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_final(t_vm *self)
{
	ft_printf("Player %d (%s) won\n", self->winner->id, self->winner->name);
}
