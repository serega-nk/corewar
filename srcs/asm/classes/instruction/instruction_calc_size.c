/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_calc_size.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:35:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/02 23:36:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

size_t	instruction_calc_size(t_instruction *self)
{
	size_t		size;
	t_argument	*argument;

	size = 1;
	vector_start(self->arguments);
	while (vector_next(self->arguments, (void **)&argument))
	{
		if (argument->arg_type & T_REG)
			size += REG_SIZE;
		else if (argument->arg_type & T_DIR)
			size += DIR_SIZE;
		else if (argument->arg_type & T_IND)
			size += IND_SIZE;
	}
	return (size);
}
