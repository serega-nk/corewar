/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sourcecode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:38:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 00:28:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

char			*instruction_sourcecode(t_instruction *self)
{
	t_argument	*argument;
	char		*temp;
	int			index;

	ft_strdel(&self->sourcecode);
	self->sourcecode = ft_xprintf("%s", self->op->name);
	index = 0;
	vector_start(self->arguments);
	while (vector_next(self->arguments, (void **)&argument))
	{
		temp = self->sourcecode;
		self->sourcecode = ft_xprintf("%s%s %s%s%ld",
			temp,
			(index > 0 ? "," : ""),
			(argument->arg_type & T_DIR ? "%" : ""),
			(argument->arg_type & T_REG ? "r" : ""),
			argument->number);
		ft_strdel(&temp);		
		index++;	
	}
	return (self->sourcecode);
}
