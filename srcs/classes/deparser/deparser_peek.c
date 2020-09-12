/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:07:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 12:05:24 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_peek(t_deparser *self, int rel, void *ptr, size_t size)
{
	ssize_t		pos;

	pos = self->pos + rel;	
	if (pos < 0 || pos + size > self->size)
		return (FALSE);
	ft_memcpy(ptr, self->data + pos, size);
	return (TRUE);
}
