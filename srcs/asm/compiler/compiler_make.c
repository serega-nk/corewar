/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:17:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 21:21:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make(t_compiler *self)
{
	if (compiler_make_load(self) &&
		compiler_make_compile(self) &&
		compiler_make_save(self))
	{
		ft_printf("Writing output program to %s\n", self->outputfile);
		return (TRUE);
	}
	else
	{
		ft_printf_fd(STDERR_FILENO, "Error compile file %s\n",
			self->sourcefile);
		return (FALSE);
	}
}
