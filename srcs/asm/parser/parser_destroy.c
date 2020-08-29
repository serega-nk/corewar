/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:32:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 20:04:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parser_destroy(t_parser **aself)
{
	if (aself && *aself)
	{
		hashtab_destroy(&(*aself)->headers);
		hashtab_destroy(&(*aself)->labels);
		token_destroy(&(*aself)->end);
		ft_memdel((void **)aself);
	}
}
