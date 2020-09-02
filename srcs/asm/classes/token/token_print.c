/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:40:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 00:41:31 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	token_print(t_token *self)
{
	if (self->value)
		ft_printf("[TOKEN][%03d:%03d] %s \"%s\"\n",
			self->ln, self->col, token_type_name(self->type), self->value);
	else
		ft_printf("[TOKEN][%03d:%03d] %s\n",
			self->ln, self->col, token_type_name(self->type));
}
