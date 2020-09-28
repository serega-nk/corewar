/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_final.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:03:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 19:43:58 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_final(t_vm *self)
{
	// ft_printf("Player %d (%s) won\n", self->winner->id, self->winner->name);
	ft_printf("Contestant %d, \"%s\", has won !\n", self->winner->id, self->winner->name);
}
