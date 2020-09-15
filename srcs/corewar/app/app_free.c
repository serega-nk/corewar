/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:12:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 16:47:40 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_free(t_app *self)
{
	arena_destroy(&self->arena);
	vector_destroy(&self->files);
	vector_destroy(&self->pending);
}
