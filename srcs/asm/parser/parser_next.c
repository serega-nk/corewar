/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:22:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 12:23:18 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*parser_next(t_parser *self)
{
	t_token		*token;

	token = parser_peek(self, 0);
	parser_move(self, 1);
	return (token);
}
