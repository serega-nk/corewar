/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 06:16:32 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:21:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	argument_destroy(t_argument **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->repr);
		ft_memdel((void **)aself);
	}
}
