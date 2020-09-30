/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:17 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 08:46:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool		process_validate(t_process *self)
{
	t_argument	*argument;
	size_t		index;

	index = 0;
	while (index < self->op->arg_count)
	{
		argument = (t_argument *)vector_get2(self->arguments, index);
		if (argument == NULL)
		{
			return (FALSE);
		}
		if ((argument->arg_type & self->op->arg_types[index]) == 0)
		{
			return (FALSE);
		}
		if (argument->arg_type & T_REG &&
			(argument->number < 1 || argument->number > REG_NUMBER))
		{
			return (FALSE);
		}
		index++;
	}
	return (TRUE);
}
