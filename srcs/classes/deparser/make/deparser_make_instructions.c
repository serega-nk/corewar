/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_make_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:26:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 16:38:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_make_instructions(t_deparser *self)
{
	while (deparser_eof(self) == FALSE)
	{
		if (deparser_next_instruction(self) == FALSE)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
