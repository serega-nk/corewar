/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_peek.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:26:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/28 22:25:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*parser_peek(t_parser *self, int rel)
{
	t_token		*token;

	if (vector_get(self->tokens, self->pos + rel, (void **)&token))
		return (token);
	return (self->end);
}
