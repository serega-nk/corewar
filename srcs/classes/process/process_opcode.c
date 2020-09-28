/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_opcode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 21:51:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:30:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool		process_opcode(t_process *self)
{
	char	code;

	vm_read(self, self->pc, &code, sizeof(code));
	vector_clean(self->instruction->arguments, &argument_destroy);
	self->instruction->op = get_op_from_code(code);
	return (self->instruction->op != NULL);
}
