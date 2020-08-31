/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_eof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:06:26 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 10:58:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	parser_eof(t_parser *self)
{
	return (parser_peek(self, 0)->type == TOKEN_TYPE_END);
}
