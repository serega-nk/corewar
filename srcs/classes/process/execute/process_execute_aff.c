/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_execute_aff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 09:39:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 18:07:03 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

/*
** INSTRUCTION
**
**   aff
**
** OPCODE
**
**   0x10
**
** 42 SUBJECT REFERENCE
**
**   aff: The opcode is 10 in the hexadecimal. There is an argument’s coding
**   byte, even if it’s a bit silly because there is only 1 argument that is
**   a registry, which is a registry, and its content is interpreted by the
**   character’s ASCII value to display on the standard output. The code is
**   modulo 256.
**
** EPITECH SUBJECT REFERENCE
**
**   This instruction is followed by a parameter encoding byte. It takes
**   a register and displays the character the ASCII code of which is
**   contained in the register. (a modulo 256 is applied to this ascii code,
**   the character is displayed on the standard output) Ex: ld %52,r3 aff r3
**   Displays ’*’ on the standard output
**
** USAGE EXAMPLE
**
**   aff r2
**
**   {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0}
*/

void	process_execute_aff(t_process *self, int v[3])
{
	ft_printf("Aff: %c\n", self->reg[v[0]]);
	if (self->vm->verbosity & VERBOSITY_OPERATIONS)
		ft_printf("Process %4d | add r%d\n", self->id, v[0]);
}
