/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 18:46:29 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/02 19:50:42 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

const char	*token_type_str(t_token *self)
{
	static const char	*names[] = {
		"COMMAND_NAME",
		"COMMAND_COMMENT",
		"STRING",
		"LABEL",
		"INSTRUCTION",
		"REGISTER",
		"DIRECT",
		"DIRECT_LABEL",
		"INDIRECT",
		"INDIRECT_LABEL",
		"ENDLINE",
		"SEPARATOR",
		"END",
		"COMMENT",
		"WHITESPACE",
	};

	return (names[self->type]);
}
