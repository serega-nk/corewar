/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_errorf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:28:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:28:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	lexer_errorf(t_lexer *self, t_token *token, char *message)
{
	lexer_error(self, token, message);
	ft_strdel(&message);
	return (FALSE);
}
