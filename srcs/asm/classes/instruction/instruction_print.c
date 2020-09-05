/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:56:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 02:31:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	instruction_print(t_instruction *self)
{
	ft_printf("[INSTR][%03d:%03d] name = %-5s code = %#.2x size = %2lu\n",
		self->token->ln, self->token->col,
		self->op->name, self->op->code, self->size);
}
