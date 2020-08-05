/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:42:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/05 21:46:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_compiler		*compiler_create(void)
{
	t_compiler	*self;

	self = (t_compiler *)ft_xmemalloc(sizeof(t_compiler));
	return (self);
}
