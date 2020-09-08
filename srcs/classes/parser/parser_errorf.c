/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errorf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:06:02 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 14:06:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	parser_errorf(t_parser *self, t_token *token, char *message)
{
	parser_error(self, token, message);
	ft_strdel(&message);
	return (FALSE);
}
