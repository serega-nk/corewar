/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_repr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:09:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:09:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

char	*label_repr(t_label *self)
{
	if (self->repr == NULL)
	{
		self->repr = ft_xprintf("[%03d:%03d] LABEL: name = %s, offset = %d",
			self->token->ln, self->token->col, self->name, self->offset);
	}
	return (self->repr);
}
