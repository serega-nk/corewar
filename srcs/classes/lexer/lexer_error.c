/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:13:09 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:14:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	lexer_error(t_lexer *self, t_token *token, char *message)
{
	self->error = TRUE;
	ft_strdel(&self->error_message);
	self->error_message = ft_xprintf(
		"%s at token %s", message, token_repr(token));
	return (FALSE);
}
