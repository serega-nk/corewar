/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:27:35 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:55:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_make_load(t_compiler *self)
{
	self->source_fd = open(self->source_fn, O_RDONLY);
	if (self->source_fd >= 0)
	{
		self->source_size = ft_get_size(self->source_fd);
		self->source_data = ft_xmalloc(self->source_size);
		if (ft_readall(self->source_fd, self->source_data, self->source_size))
			return (TRUE);
	}
	return (compiler_errorf(self, ft_xprintf(
		"Can't read source file %s", self->source_fn)));
}
