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

	vector_clean(self->arguments, &argument_destroy);
	code = '\0';
	vm_read(self->vm, process_addr(self), &code, sizeof(code));
	process_step(self, sizeof(code));
	self->op = get_op_from_code(code);
	return ((self->op) != NULL);
}
