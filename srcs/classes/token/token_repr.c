/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_repr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:43:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:08:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static char		*g_types[] = {
	"WORD",
	"STRING",
	"COMMENT",
	"WHITESPACE",
	"LABEL",
	"SEPARATOR",
	"DIRECT",
	"ENDLINE",
	"END"
};

char	*token_repr(t_token *self)
{
	if (self->repr == NULL)
	{
		if (self->value)
			self->repr = ft_xprintf("[%03d:%03d] TOKEN: %s \"%s\"",
				self->ln, self->col, g_types[self->type], self->value);
		else
			self->repr = ft_xprintf("[%03d:%03d] TOKEN: %s",
				self->ln, self->col, g_types[self->type]);
	}
	return (self->repr);
}
