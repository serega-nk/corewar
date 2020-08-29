/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_has_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 16:46:54 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 19:09:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_has_header(t_parser *self)
{
	return (parser_peek(self, 0)->type == TOKEN_TYPE_WORD &&
			parser_peek(self, 1)->type == TOKEN_TYPE_WHITESPACE &&
			parser_peek(self, 2)->type == TOKEN_TYPE_STRING);
}
