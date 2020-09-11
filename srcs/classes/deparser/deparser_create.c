/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:12:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 16:33:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_deparser	*deparser_create(char *data, size_t size)
{
	t_deparser	*self;

	self = (t_deparser *)ft_xmemalloc(sizeof(t_deparser));
	self->data = data;
	self->size = size;
	self->instructions = vector_create();
	return (self);
}
