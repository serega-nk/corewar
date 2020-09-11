/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:12:23 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 16:32:39 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	deparser_destroy(t_deparser **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->error_message);
		vector_clean((*aself)->instructions, &instruction_destroy);
		vector_destroy(&(*aself)->instructions);
		ft_memdel((void **)aself);
	}
}
