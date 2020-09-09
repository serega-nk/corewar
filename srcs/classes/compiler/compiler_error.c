/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:22:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:54:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_error(t_compiler *self, char *message)
{
	self->error = TRUE;
	ft_strdel(&self->error_message);
	self->error_message = ft_xprintf("%s", message);
	return (FALSE);
}
