/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_print_labels.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 22:27:38 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 13:12:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	compiler_print_labels(t_compiler *self)
{
	t_label		*label;

	ft_printf("=== LABELS: ===\n");
	hashtab_start(self->parser->labels);
	while (hashtab_next_kv(self->parser->labels, NULL, (void **)&label))
	{
		ft_printf("%s\n", label_repr(label));
	}
}
