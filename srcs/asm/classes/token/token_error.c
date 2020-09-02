/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:34:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 00:51:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	token_error(t_token *self, char *str)
{
	if (str)
		ft_printf_fd(STDERR_FILENO, "%s at token ", str);
	if (self->value)
		ft_printf_fd(STDERR_FILENO, "[TOKEN][%03d:%03d] %s \"%s\"\n",
			self->ln, self->col, token_type_name(self->type), self->value);
	else
		ft_printf_fd(STDERR_FILENO, "[TOKEN][%03d:%03d] %s\n",
			self->ln, self->col, token_type_name(self->type));
	return (FALSE);
}
