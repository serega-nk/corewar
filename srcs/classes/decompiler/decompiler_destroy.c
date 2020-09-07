/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompiler_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:15:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 01:27:10 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	decompiler_destroy(t_decompiler **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)&(*aself)->bytecode_data);
		ft_close(&(*aself)->bytecode_fd);
		ft_memdel((void **)aself);
	}
}
