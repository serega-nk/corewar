/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:12:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 18:41:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_free(t_app *self)
{
	vm_destroy(&self->vm);
	vector_destroy(&self->files);
	vector_destroy(&self->pending);
}
