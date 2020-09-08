/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:34:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_label		*label_create(t_token *token, char *name, int index)
{
	t_label	*self;

	self = (t_label *)ft_xmemalloc(sizeof(t_label));
	self->token = token;
	self->name = ft_xstrdup(name);
	self->index = index;
	return (self);
}
