/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:16:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 18:56:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*lexer_value(t_lexer *self)
{
	if (self->start > self->pos)
		return (NULL);
	return (ft_xstrndup(self->input + self->start, self->pos - self->start));
}
