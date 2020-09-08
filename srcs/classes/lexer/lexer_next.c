/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:49:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

char	lexer_next(t_lexer *self)
{
	char	ch;

	ch = lexer_peek(self, 0);
	if (ch == ENDLINE_CHAR)
	{
		self->ln++;
		self->col = 0;
	}
	self->col++;
	self->pos++;
	return (ch);
}
