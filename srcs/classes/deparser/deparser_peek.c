/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:07:36 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:36:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_peek(t_deparser *self, int rel, void *ptr, size_t size)
{
	if (self->pos + rel < 0 || self->pos + rel + size > self->size)
		return (FALSE);
	ft_memcpy(ptr, self->data + self->pos + rel, size);
	return (TRUE);
}
