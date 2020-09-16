/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 21:37:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/16 16:13:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		vm_print(t_vm *self)
{
	size_t			index;
	size_t			pos;
	unsigned char	ch;

	index = 0;
	while (index < sizeof(self->mem))
	{
		ft_printf("0x%.4x :", index);
		pos = 0;
		while (pos < 64)
		{
			if (index + pos < sizeof(self->mem))
				ch = (unsigned char)self->mem[index + pos];
			else
				ch = 0;
			ft_printf(" %.2x", ch);
			pos++;
		}
		ft_printf("\n");
		index += 64;
	}
}
