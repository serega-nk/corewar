/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 00:32:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 23:56:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	argument_print(t_argument *self)
{
	ft_printf("[%03d:%03d] ARGUMENT: type =",
		self->token->ln, self->token->col);
	if (self->arg_type & T_REG)
		ft_printf(" T_REG");
	if (self->arg_type & T_DIR)
		ft_printf(" T_DIR");
	if (self->arg_type & T_IND)
		ft_printf(" T_IND");
	if (self->arg_type & T_LAB)
		ft_printf(" T_LAB");
	ft_printf(", size = %lu, value = %d", self->size, self->number);
}
