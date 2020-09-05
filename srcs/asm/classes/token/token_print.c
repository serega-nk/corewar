/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:40:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 00:53:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void			token_print(t_token *self)
{
	if (self->value)
		ft_printf("[%03d:%03d] TOKEN: %s \"%s\"",
			self->ln, self->col, g_types[self->type], self->value);
	else
		ft_printf("[%03d:%03d] TOKEN: %s",
			self->ln, self->col, g_types[self->type]);
}
