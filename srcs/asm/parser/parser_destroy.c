/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:32:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/30 18:59:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parser_destroy(t_parser **aself)
{
	if (aself && *aself)
	{
		//vector_clean((*aself)->instructions, &instruction_destroy)
		vector_destroy(&(*aself)->instructions);
		hashtab_destroy(&(*aself)->commands);
		hashtab_destroy(&(*aself)->labels);
		token_destroy(&(*aself)->end);
		ft_memdel((void **)aself);
	}
}
