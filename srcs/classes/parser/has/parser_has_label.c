/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_has_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 19:08:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	parser_has_label(t_parser *self)
{
	return (parser_peek(self, 0)->type == TOKEN_TYPE_WORD &&
			parser_peek(self, 1)->type == TOKEN_TYPE_LABEL);
}
