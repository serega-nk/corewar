/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:15:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 18:31:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	decompiler_destroy(t_decompiler **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->error_message);
		vector_clean((*aself)->lines, &ft_strdel);
		vector_destroy(&(*aself)->lines);
		deparser_destroy(&(*aself)->deparser);
		ft_memdel((void **)&(*aself)->bytecode_data);
		ft_close(&(*aself)->bytecode_fd);
		ft_memdel((void **)aself);
	}
}
