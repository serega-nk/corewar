/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:12:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disclasses.h"

t_bool	decompiler_make_print(t_decompiler *self)
{
	ft_printf(".name = \"%s\"\n", self->header.prog_name);
	ft_printf(".comment = \"%s\"\n", self->header.comment);
	ft_printf("\n");		
	return (TRUE);
}
