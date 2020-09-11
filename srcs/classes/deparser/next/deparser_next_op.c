/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_next_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:39:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:39:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool		deparser_next_op(t_deparser *self, t_instruction *instruction)
{
	char	opcode;

	if (deparser_next(self, &opcode, sizeof(opcode)) == FALSE)
		return (deparser_error(self, "ERROR OP EOF"));
	instruction->op = get_op_from_code(opcode);
	if (instruction->op == NULL)
		return (deparser_error(self, "ERROR OPCODE"));
	return (TRUE);
}
