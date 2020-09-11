/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 23:59:53 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 23:59:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	decompiler_error(t_decompiler *self, char *message)
{
	self->error = TRUE;
	ft_strdel(&self->error_message);
	self->error_message = ft_xprintf("%s", message);
	return (FALSE);
}
