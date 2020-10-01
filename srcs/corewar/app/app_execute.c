/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:12:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 04:58:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_execute(t_app *self)
{
	self->vm = vm_create(self->files, self->verbosity,
		self->nbr_cycles, self->option_d ? 64 : 32);
	vm_run(self->vm);
}
