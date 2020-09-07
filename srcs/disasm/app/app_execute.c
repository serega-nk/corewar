/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:30:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 23:28:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	app_execute(t_app *self)
{
	if (self->argc > 0)
	{
		self->decompiler = decompiler_create(self->argv[0]);
		ft_printf("OK\n");
		decompiler_destroy(&self->decompiler);
	}
}
