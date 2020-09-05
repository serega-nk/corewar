/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_bytecode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:01:41 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 01:30:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	compiler_print_bytecode(t_compiler *self)
{
	ft_printf("=== BYTECODE: ===\n");
	ft_print_memory(self->output_data, self->output_size);
}
