/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 22:26:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:18:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	compiler_print_tokens(t_compiler *self)
{
	t_token		*token;

	ft_printf("=== TOKENS: ===\n");
	vector_start(self->lexer->tokens);
	while (vector_next(self->lexer->tokens, (void **)&token))
	{
		ft_printf("%s\n", token_repr(token));
	}
}
