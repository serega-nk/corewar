/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:37:26 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/12 23:15:19 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	lexer_peek(t_lexer *self, int relative_position)
{
	int	position;

	position = self->pos + relative_position;
	if (position >= 0 && position < self->length)
		return (self->input[position]);
	return (END_CHAR);
}
