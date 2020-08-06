/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 21:42:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/05 21:51:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		compiler_destroy(t_compiler **aself)
{
	if (aself && *aself)
	{
		parser_destroy(&(*aself)->parser);
		lexer_destroy(&(*aself)->lexer);
		ft_strdel(&(*aself)->text);
		ft_memdel((void **)aself);
	}
}
