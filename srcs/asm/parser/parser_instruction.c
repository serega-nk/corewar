/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_instruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:41:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/30 20:33:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


t_bool	parser_instruction_arg(t_parser *self)
{
	t_token		*token;
	t_bool		is_dir;
	t_bool		is_lab;

	if ((is_dir = (parser_peek(self, 0)->type == TOKEN_TYPE_DIRECT)))
		parser_move(self, 1);
	if ((is_lab = (parser_peek(self, 0)->type == TOKEN_TYPE_LABEL)))
		parser_move(self, 1);
	token = parser_peek(self, 0);
	if (token->type != TOKEN_TYPE_WORD)
		return (token_error(token, "1\n"));
	

}


t_bool	parser_instruction(t_parser *self)
{
	t_token		*token;
	t_op		*op;
	int			index;
	t_bool		is_dir;
	t_bool		is_lab;

	token = parser_peek(self, 0);
	if ((op = op_get(token->value)) == NULL)
		return (token_error(token, "Invalid instruction at token "));
	parser_move(self, 1);
	if (parser_peek(self, 0)->type != TOKEN_TYPE_WHITESPACE)
		return (token_error(parser_peek(self, 0), "Syntax error at token "));
	parser_move(self, 1);	
	if ((is_dir = (parser_peek(self, 0)->type == TOKEN_TYPE_DIRECT)))
		parser_move(self, 1);
	if ((is_lab = (parser_peek(self, 0)->type == TOKEN_TYPE_LABEL)))
		parser_move(self, 1);
	
	if (parser_peek(self, 0)->type == TOKEN_TYPE_WORD)
	{
		if 

	}
	
	T_

	if (parser_peek(self, 0)->type == TOKEN_TYPE_LABEL)
	{

	}	
	
	
// registry
	// direct



	token = parser_peek(self, 0);

	

	parser_peek(self, 0)
	while (parser_peek(self, 0)->type == TOKEN_TYPE_WHITESPACE)
		parser_move(self, 1);
	token = parser_peek(self, 0);


	index = 0;
	test = parser_argument(self, op->args[index]);
	
	
	if (op->args[index] & T_REG)
	
	


	while ()

	
	op->argc
	ft_printf("INSTRUCTION %s\n", key);
	return (FALSE);
}
