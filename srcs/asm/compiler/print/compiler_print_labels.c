/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_labels.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 22:27:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 22:55:28 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	compiler_print_labels(t_compiler *self)
{
	t_label		*label;

	ft_printf("=== LABELS: ===\n");
	hashtab_start(self->parser->labels);
	while (hashtab_next_kv(self->parser->labels, NULL, (void **)&label))
	{
		label_print(label);
	}
}
