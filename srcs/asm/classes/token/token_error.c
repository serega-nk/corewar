/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:34:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 09:46:09 by bconchit         ###   ########.fr       */
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

t_bool			token_error(t_token *self, char *str)
{
	if (str)
		ft_printf_fd(STDOUT_FILENO, "%s at token ", str);
	if (self->value)
		ft_printf_fd(STDOUT_FILENO, "[TOKEN][%03d:%03d] %s \"%s\"\n",
			self->ln, self->col, g_types[self->type], self->value);
	else
		ft_printf_fd(STDOUT_FILENO, "[TOKEN][%03d:%03d] %s\n",
			self->ln, self->col, g_types[self->type]);
	return (FALSE);
}
