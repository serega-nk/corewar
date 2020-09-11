/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_errorf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 23:59:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/10 19:10:43 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	decompiler_errorf(t_decompiler *self, char *message)
{
	decompiler_error(self, message);
	ft_strdel(&message);
	return (FALSE);
}
