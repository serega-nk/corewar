/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_save.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:28:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 00:04:17 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make_save(t_compiler *self)
{
	self->output_fd = open(self->outputfile,
		O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (self->output_fd >= 0)
	{
		if (ft_writeall(self->output_fd, self->output_data, self->output_size))
			return (TRUE);
	}
	ft_printf("Can't write output file %s", self->outputfile);
	return (FALSE);
}
