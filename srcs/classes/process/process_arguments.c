/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:51:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:26:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"



// static t_arg_type	get_arg_type(t_arg_type types, size_t index)
// {
// 	return ((types >> (sizeof(types) * 8 - index * 2)) & 0b11);
// }

// t_bool				process_arg_types(t_deparser *self,
// 	t_instruction *instruction)
// {
// 	char	types;
// 	size_t	index;

// 	if (instruction->op->use_types)
// 	{
// 		if (deparser_next(self, &types, sizeof(types)) == FALSE)
// 			return (deparser_error(self, "ERROR ARG TYPES EOF"));
// 		instruction->arg_types = ft_xmemalloc(
// 			instruction->op->arg_count * sizeof(t_arg_type));
// 		index = 0;
// 		while (index < instruction->op->arg_count)
// 		{
// 			instruction->arg_types[index] = get_arg_type(types, index + 1);
// 			if ((instruction->arg_types[index] &
// 				instruction->op->arg_types[index]) == 0)
// 				return (deparser_error(self, "ERROR ARG TYPE"));
// 			index++;
// 		}
// 	}
// 	else
// 	{
// 		instruction->arg_types = ft_xmemdup(instruction->op->arg_types,
// 			instruction->op->arg_count * sizeof(t_arg_type));
// 	}
// 	return (TRUE);
// }

// static void		argument_fix_signed(t_argument *self)
// {
// 	size_t		size;

// 	size = sizeof(self->number);
// 	if (size > self->size && self->number >> (self->size * 8 - 1) == 0b1)
// 	{
// 		memset((char *)&self->number + self->size, -1, size - self->size);
// 	}
// }

static void		ft_signed(void *data, size_t size, size_t max_size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)data;
	if (max_size > size && size > 0 && ptr[size - 1] & 0x80)
	{
		ft_memset(ptr + size, -1, max_size - size);
	}
}

t_bool			process_arguments(t_process *self)
{
	t_argument	*argument;
	size_t		index;

	index = 0;
	while (index < self->op->arg_count)
	{
		argument = argument_create();
		vector_push_back(self->arguments, argument);
		argument->arg_type = self->arg_types[index];
		argument_calc_size(argument, self->op->dir_ind);
		vm_read(self->vm, self->pc, &argument->number, argument->size);
		ft_memrev(&argument->number, argument->size);
		ft_signed(&argument->number, argument->size, sizeof(argument->number));		
		process_move(self, argument->size);
		ft_printf("#### ARGUMENT %#.2b = %d\n", argument->arg_type, argument->number);
		index++;
	}
	return (TRUE);
}
