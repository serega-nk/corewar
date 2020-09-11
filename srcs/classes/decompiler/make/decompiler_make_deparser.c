/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make_deparser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:34:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 18:34:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	decompiler_make_deparser(t_decompiler *self)
{
	self->deparser = deparser_create(self->bytecode_data, self->bytecode_size);
	if (deparser_make(self->deparser) == FALSE)
		return (decompiler_error(self, self->deparser->error_message));
	return (TRUE);
}
