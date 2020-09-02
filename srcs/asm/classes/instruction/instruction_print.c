/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:56:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 01:01:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	instruction_print(t_instruction *self)
{
	ft_printf("[INSTR][%03d:%03d] opcode == %#.2x\n",
		self->token->ln, self->token->col, self->op->code);
}
