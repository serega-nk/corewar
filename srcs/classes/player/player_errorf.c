/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_errorf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:49:11 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 17:04:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	player_errorf(t_player *self, char *message)
{
	player_error(self, message);
	ft_strdel(&message);
	return (FALSE);
}
