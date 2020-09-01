/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:38:41 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 22:59:48 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		token_destroy(t_token **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->value);
		ft_memdel((void **)aself);
	}
}
