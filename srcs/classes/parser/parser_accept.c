/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_accept.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:11:39 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 12:13:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_accept(t_parser *self, t_token_type type)
{
	if (parser_peek(self, 0)->type == type)
	{
		parser_move(self, 1);
		return (TRUE);
	}
	return (FALSE);
}
