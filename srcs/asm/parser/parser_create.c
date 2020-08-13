/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:59:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 23:37:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser	*parser_create(t_list *tokens)
{
	t_parser	*self;

	self = (t_parser *)ft_xmemalloc(sizeof(t_parser));
	self->iter = list_iter_create(tokens);
	return (self);
}
