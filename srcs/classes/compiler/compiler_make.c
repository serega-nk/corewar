/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 19:17:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:27:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_make(t_compiler *self, t_bool multi)
{
	if (compiler_make_load(self) &&
		compiler_make_analyzed(self) &&
		compiler_make_prog_size(self) &&
		compiler_make_convert_labels(self) &&
		compiler_make_header(self) &&
		compiler_make_bytecode(self) &&
		compiler_make_save(self))
	{
		return (TRUE);
	}
	return (FALSE);
}

// 	t_bool	result;

// 	if (multi)
// 	{
// 		ft_printf("Compile file: %s\n", self->source_fn);
// 		ft_printf("┗━━ ");
// 	}
// 	result = (
// 		compiler_make_load(self) &&
// 		compiler_make_analyzed(self) &&
// 		compiler_make_prog_size(self) &&
// 		compiler_make_convert_labels(self) &&
// 		compiler_make_header(self) &&
// 		compiler_make_bytecode(self) &&
// 		compiler_make_save(self) &&
// 		ft_printf("{green}Writing output program to %s{eoc}",
// 			self->bytecode_fn));
// 	ft_printf("\n");
// 	return (result);
// }
