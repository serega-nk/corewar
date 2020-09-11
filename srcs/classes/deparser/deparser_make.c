/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:18:37 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:40:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_make(t_deparser *self)
{
	if (deparser_make_header(self) &&
		deparser_make_instructions(self))
	{
		return (TRUE);
	}
	return (FALSE);
}
