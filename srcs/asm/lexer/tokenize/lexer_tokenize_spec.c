/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tokenize_spec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:59:01 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 20:06:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	lexer_tokenize_spec(t_lexer *self, t_token *token)
{
	token = (t_token *)token;
	lexer_next(self);
	return (TRUE);
}
