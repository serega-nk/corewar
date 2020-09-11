/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:30:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 18:52:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_next(t_deparser *self, void *ptr, size_t size)
{
	if (deparser_peek(self, 0, ptr, size) == FALSE)
		return (FALSE);
	deparser_move(self, size);
	return (TRUE);
}
