/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:32:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:49:13 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	parser_destroy(t_parser **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->error_message);
		vector_destroy(&(*aself)->convert_labels);
		vector_clean((*aself)->instructions, &instruction_destroy);
		vector_destroy(&(*aself)->instructions);
		hashtab_clean((*aself)->labels, &label_destroy);
		hashtab_destroy(&(*aself)->labels);
		token_destroy(&(*aself)->end);
		ft_memdel((void **)aself);
	}
}
