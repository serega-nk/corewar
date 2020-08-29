/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:34:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 20:17:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*label_create(char *name, int index)
{
	t_label	*self;

	self = (t_label *)ft_xmemalloc(sizeof(t_label));
	self->name = ft_xstrdup(name);
	self->index = index;
	return (self);
}
