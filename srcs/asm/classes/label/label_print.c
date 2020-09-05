/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:44:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 00:54:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_print(t_label *self)
{
	ft_printf("[%03d:%03d] LABEL: name = %s, offset = %d",
		self->token->ln, self->token->col, self->name, self->offset);
}
