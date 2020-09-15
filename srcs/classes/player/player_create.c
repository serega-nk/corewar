/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:14:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 19:14:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_player	*player_create(char *name, char *comment)
{
	t_player	*self;

	self = (t_player *)ft_xmemalloc(sizeof(t_player));
	self->name = name;
	self->comment = comment;
	return (self);
}
