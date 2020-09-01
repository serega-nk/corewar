/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:07:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 18:16:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_compiler	*compiler_create(t_parser *parser)
{
	t_compiler	*self;

	self = (t_compiler *)ft_xmemalloc(sizeof(t_compiler));
	self->parser = parser;
	return (self);
}
