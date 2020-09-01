/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:07:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 18:53:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_next_command(t_parser *self)
{
	t_token		*t0;
	t_token		*t2;

	t0 = parser_peek(self, 0);
	t2 = parser_peek(self, 2);
	if (parser_accept(self, TOKEN_TYPE_WORD) == FALSE || 
		parser_accept(self, TOKEN_TYPE_WHITESPACE) == FALSE ||
		parser_accept(self, TOKEN_TYPE_STRING) == FALSE)
		return (token_error(parser_peek(self, 0), "Syntax error"));
	if (ft_strequ(t0->value, NAME_CMD_STRING))
	{
		if (self->command_name)
			return (token_error(t0, "Command is already defined in the scope"));
		if (ft_strlen(t2->value) > PROG_NAME_LENGTH)
		{
			ft_printf_fd(STDERR_FILENO, 
				"Champion name too long (Max length %d)", PROG_NAME_LENGTH);
			return (token_error(t2, NULL));
		}			
		self->command_name = t2->value;
	}
	else if (ft_strequ(t0->value, COMMENT_CMD_STRING))
	{
		if (self->command_comment)
			return (token_error(t0, "Command is already defined in the scope"));
		if (ft_strlen(t2->value) > COMMENT_LENGTH)
		{
			ft_printf_fd(STDERR_FILENO, 
				"Champion comment too long (Max length %d)", COMMENT_LENGTH);
			return (token_error(t2, NULL));
		}			
		self->command_comment = t2->value;
	}
	else
		return (token_error(t0, "Invalid name of the command"));
	if (parser_accept(self, TOKEN_TYPE_WHITESPACE) == FALSE &&
		parser_accept(self, TOKEN_TYPE_COMMENT) == FALSE &&
		parser_accept(self, TOKEN_TYPE_ENDLINE) == FALSE)
		return (token_error(parser_peek(self, 0), "Syntax error"));
	return (TRUE);
}
