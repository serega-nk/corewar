/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:51:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:57:37 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	parser_error(t_parser *self, t_token *token, char *message)
{
	ft_strdel(&self->error_message);
	self->error_message = ft_xprintf(
		"%s at token %s", message, token_repr(token));
	return (FALSE);
}
