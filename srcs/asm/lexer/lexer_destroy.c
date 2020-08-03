/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 20:10:22 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/03 21:01:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		lexer_destroy(t_lexer **aself)
{
	if (aself && *aself)
	{
		ft_memdel((void **)aself);
	}
}
