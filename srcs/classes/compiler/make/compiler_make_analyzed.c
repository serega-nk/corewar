/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_analyzed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:09:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 22:09:46 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_make_analyzed(t_compiler *self)
{
	self->lexer = lexer_create(self->source_data, self->source_size);
	if (lexer_tokenize(self->lexer) == FALSE)
		return (FALSE);
	self->parser = parser_create(self->lexer->tokens);
	if (parser_make(self->parser) == FALSE)
		return (FALSE);
	return (TRUE);
}
