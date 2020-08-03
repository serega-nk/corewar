/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:10:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/02 20:19:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		lexer_destroy(t_lexer **aself)
{
	if (aself && *aself)
	{
		list_clean((*aself)->tokens, &token_destroy);
		list_destroy(&(*aself)->tokens);
		ft_memdel((void **)aself);
	}
}
