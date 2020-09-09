/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_repr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:16:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:30:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

char	*argument_repr(t_argument *self)
{
	char	*str;

	ft_strdel(&self->repr);
	if (self->arg_type & T_REG)
		str = "T_REG";
	else if (self->arg_type & T_DIR)
		str = "T_DIR";
	else if (self->arg_type & T_IND)
		str = "T_IND";
	else
		str = "NONE";
	self->repr = ft_xprintf(
		"[%03d:%03d] ARGUMENT: type = %s, size = %lu, value = %d",
		self->token->ln, self->token->col, str, self->size, self->number);
	return (self->repr);
}
