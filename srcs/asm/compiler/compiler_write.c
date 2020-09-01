/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:34:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 21:38:41 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_write(t_compiler *self, void *addr, size_t size)
{
	// int		ret;

	// while (TRUE)
	// {
	// 	ret = write(self->fd, addr, size)
	// 	if (ret < 0)
	// 		return (compiler_error(self, "ERROR WRITE"));
	// 	if (ret == 0)
	// 		break ;
	// 	size -= ret;
	// 	if (size == 0)

	// 	addr += ret;
	// }
	

	return (write(self->fd, addr, size) == size);
}
