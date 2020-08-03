/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:16:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/03 21:01:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lexer		*lexer_create(void)
{
	t_lexer	*self;

	self = (t_lexer *)ft_xmemalloc(sizeof(t_lexer));
	return (self);
}
