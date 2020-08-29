/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:41:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 21:31:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_instruction(t_parser *self)
{
	char	*key;
	t_op	*op;

	key = parser_peek(self, 0)->value;
	if ((op = op_get(key)) == NULL)
	{
		ft_printf("Invalid instruction at token ");
		token_print(parser_peek(self, 0));
		return (FALSE);
	}
	// index = 0;
	// while (index < op->argc)
	// {
		
	// }
	// op->argc
	ft_printf("INSTRUCTION %s\n", key);

	return (FALSE);
}
