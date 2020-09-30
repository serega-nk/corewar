/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 08:46:25 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:26:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_arg_type	get_arg_type(t_arg_type types, size_t index)
{
	int		val;

	val = (types >> (sizeof(types) * 8 - index * 2)) & 0b11;
	if (val == REG_CODE)
		return (T_REG);
	if (val == IND_CODE)
		return (T_IND);
	if (val == DIR_CODE)
		return (T_DIR);
	return (0);
}

t_bool				process_arg_types(t_process *self)
{
	char	types;
	size_t	index;

	ft_memcpy(self->arg_types, self->op->arg_types, sizeof(self->arg_types));
	if (self->op->use_types)
	{
		types = '\0';
		vm_read(self->vm, self->pc + self->step, &types, sizeof(types));
		ft_memrev(&types, sizeof(types));
		process_step(self, sizeof(types));
		index = 0;
		while (index < MAX_ARG_TYPES)
		{
			self->arg_types[index] = get_arg_type(types, index + 1);
			index++;
		}
	}
	return (TRUE);
}
