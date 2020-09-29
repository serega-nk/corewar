/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_next_argument.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:48:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 23:57:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool			deparser_next_argument(t_deparser *self,
	t_instruction *instruction, size_t index)
{
	t_argument	*argument;

	argument = argument_create();
	vector_push_back(instruction->arguments, argument);
	argument->arg_type = instruction->arg_types[index];
	argument_calc_size(argument, instruction->op->dir_ind);
	if (deparser_next(self, &argument->number, argument->size) == FALSE)
		return (deparser_error(self, "ERROR ARGUMENT EOF"));
	ft_memrev(&argument->number, argument->size);
	ft_signed(&argument->number, argument->size, sizeof(argument->number));
	return (TRUE);
}
