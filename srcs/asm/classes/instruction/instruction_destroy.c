/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 03:28:46 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 19:49:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	instruction_destroy(t_instruction **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)&(*aself)->bytecode);
		vector_clean((*aself)->arguments, &argument_destroy);
		vector_destroy(&(*aself)->arguments);
		ft_memdel((void **)aself);
	}
}
