/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_eof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:49:21 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/14 04:59:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_bool	vector_eof(t_vector *self)
{
	return (self->pos >= (ssize_t)self->count);
}
