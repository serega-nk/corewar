/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:34:45 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 23:35:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	token_error(t_token *self, char *str)
{
	if (str)
		ft_printf("{red}%s at token{eoc} ", str);
	token_print(self);
	return (FALSE);
}
