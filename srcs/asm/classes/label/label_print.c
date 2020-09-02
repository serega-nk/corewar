/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:44:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 00:58:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_print(t_label *self)
{
	ft_printf("[LABEL][%03d:%03d] name == %s, offset == %d\n",
		self->token->ln, self->token->col, self->name, self->offset);
}
