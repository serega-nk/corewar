/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:08:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 00:07:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	compiler_destroy(t_compiler **aself)
{
	if (aself && *aself)
	{
		ft_close(&(*aself)->output_fd);
		ft_strdel(&(*aself)->output_data);
		parser_destroy(&(*aself)->parser);
		lexer_destroy(&(*aself)->lexer);
		ft_strdel(&(*aself)->source_data);
		ft_close(&(*aself)->source_fd);
		ft_strdel(&(*aself)->outputfile);
		ft_memdel((void **)aself);
	}
}
