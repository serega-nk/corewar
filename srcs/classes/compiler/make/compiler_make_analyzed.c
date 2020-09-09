/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_analyzed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:09:13 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:56:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_make_analyzed(t_compiler *self)
{
	self->lexer = lexer_create(self->source_data, self->source_size);
	if (lexer_tokenize(self->lexer) == FALSE)
		return (compiler_error(self, self->lexer->error_message));
	self->parser = parser_create(self->lexer->tokens);
	if (parser_make(self->parser) == FALSE)
		return (compiler_error(self, self->parser->error_message));
	return (TRUE);
}
