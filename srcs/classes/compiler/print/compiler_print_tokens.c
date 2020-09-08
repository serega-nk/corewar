/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 22:26:50 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
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
		token_print(token);
		ft_printf("\n");
	}
}
