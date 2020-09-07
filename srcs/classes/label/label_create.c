/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:34:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 16:29:56 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label		*label_create(t_token *token, char *name, int index)
{
	t_label	*self;

	self = (t_label *)ft_xmemalloc(sizeof(t_label));
	self->token = token;
	self->name = ft_xstrdup(name);
	self->index = index;
	return (self);
}
