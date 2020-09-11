/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_make.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 00:06:47 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 18:35:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

t_bool		decompiler_make(t_decompiler *self)
{
	if (decompiler_make_load(self) &&
		decompiler_make_deparser(self) &&
	 	decompiler_make_lines(self))
	{
		return (TRUE);
	}
	return (FALSE);
}
