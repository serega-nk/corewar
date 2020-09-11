/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:17:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 16:17:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_error(t_deparser *self, char *message)
{
	self->error = TRUE;
	ft_strdel(&self->error_message);
	self->error_message = ft_xprintf("%s", message);
	return (FALSE);
}
