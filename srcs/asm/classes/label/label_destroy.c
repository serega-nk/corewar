/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:38:41 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/29 20:17:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	label_destroy(t_label **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->name);
		ft_memdel((void **)aself);
	}
}
