/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_next_arg_types.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:40:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:36:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

static t_arg_type	get_arg_type(t_arg_type types, size_t index)
{
	return ((types >> (sizeof(types) * 8 - index * 2)) & 0b11);
}

t_bool				deparser_next_arg_types(t_deparser *self,
	t_instruction *instruction)
{
	char	types;
	size_t	index;

	if (instruction->op->use_types)
	{
		if (deparser_next(self, &types, sizeof(types)) == FALSE)
			return (deparser_error(self, "ERROR ARG TYPES EOF"));
		instruction->arg_types = ft_xmemalloc(
			instruction->op->arg_count * sizeof(t_arg_type));
		index = 0;
		while (index < instruction->op->arg_count)
		{
			instruction->arg_types[index] = get_arg_type(types, index + 1);
			if ((instruction->arg_types[index] &
				instruction->op->arg_types[index]) == 0)
				return (deparser_error(self, "ERROR ARG TYPE"));
			index++;
		}
	}
	else
	{
		instruction->arg_types = ft_xmemdup(instruction->op->arg_types,
			instruction->op->arg_count * sizeof(t_arg_type));
	}
	return (TRUE);
}
