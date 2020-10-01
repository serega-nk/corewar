/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:12:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 04:38:25 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_execute(t_app *self)
{
	self->vm = vm_create(self->files, self->nbr_cycles);
	self->vm->verbosity = 31;
	vm_run(self->vm);
}
