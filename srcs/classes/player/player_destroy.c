/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:13:55 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 17:05:54 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	player_destroy(t_player **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->error_message);
		ft_close(&(*aself)->fd);
		ft_memdel((void **)&(*aself)->data);
		ft_strdel(&(*aself)->comment);
		ft_strdel(&(*aself)->name);
		ft_memdel((void **)aself);
	}
}
