/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:10:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:49:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void		lexer_destroy(t_lexer **aself)
{
	if (aself && *aself)
	{
		ft_strdel(&(*aself)->error_message);
		vector_clean((*aself)->tokens, &token_destroy);
		vector_destroy(&(*aself)->tokens);
		ft_memdel((void **)aself);
	}
}
