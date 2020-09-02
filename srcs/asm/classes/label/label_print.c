/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:44:16 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 00:47:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_print(t_label *label)
{
	ft_printf("[LABEL][%03d:%03d] name == %s, offset == %d\n",
		label->token->ln, label->token->col, label->name, label->offset);
}
