/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:38:41 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:54:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		token_destroy(t_token **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->repr);
		ft_strdel(&(*aself)->value);
		ft_memdel((void **)aself);
	}
}
