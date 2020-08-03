/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:34:59 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/03 20:28:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*token_create(void)
{
	t_token	*self;

	self = (t_token *)ft_xmemalloc(sizeof(t_token));
	return (self);
}
