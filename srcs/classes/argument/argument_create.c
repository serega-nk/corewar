/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 06:11:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 11:14:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_argument	*argument_create(void)
{
	t_argument	*self;

	self = (t_argument *)ft_xmemalloc(sizeof(t_argument));
	return (self);
}
