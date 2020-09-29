/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:17:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 22:15:03 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_destroy(t_process **aself)
{
	if (aself && *aself)
	{
		vector_clean((*aself)->arguments, &argument_destroy);
		vector_destroy(&(*aself)->arguments);
		ft_memdel((void **)aself);
	}
}
