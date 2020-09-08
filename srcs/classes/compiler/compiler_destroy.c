/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:08:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:48:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	compiler_destroy(t_compiler **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->error_message);
		ft_close(&(*aself)->bytecode_fd);
		ft_memdel((void **)&(*aself)->bytecode_data);
		parser_destroy(&(*aself)->parser);
		lexer_destroy(&(*aself)->lexer);
		ft_memdel((void **)&(*aself)->source_data);
		ft_close(&(*aself)->source_fd);
		ft_strdel(&(*aself)->bytecode_fn);
		ft_memdel((void **)aself);
	}
}
