/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_has_instruction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:06:12 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 03:22:59 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_has_instruction(t_parser *self)
{
	return (parser_peek(self, 0)->type == TOKEN_TYPE_WORD &&
			parser_peek(self, 1)->type == TOKEN_TYPE_WHITESPACE);
}
