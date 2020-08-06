/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:59:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 20:32:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_parser		*parser_create(void)
{
	t_parser	*self;

	self = (t_parser *)ft_xmemalloc(sizeof(t_parser));
	return (self);
}
