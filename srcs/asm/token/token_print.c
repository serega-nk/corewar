/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:43:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/02 19:37:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


void	token_print(t_token *self)
{
	ft_printf("[TOKEN][%03d:%03d] %s \"%s\"\n", self->lineno, self->column);
}
