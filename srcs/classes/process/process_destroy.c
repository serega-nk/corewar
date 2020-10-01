/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:17:06 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 18:37:08 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	process_destroy(t_process **aself)
{
	if (aself && *aself)
	{
		if ((*aself)->vm->verbosity & VERBOSITY_DEATHS)
			ft_printf("Process %u hasn't lived for %d cycles (Cycles_to_die %d)\n", (*aself)->id,
			(*aself)->vm->cycles_num - (*aself)->last_live, (*aself)->vm->cycles_to_die);
		vector_clean((*aself)->arguments, &argument_destroy);
		vector_destroy(&(*aself)->arguments);
		ft_memdel((void **)aself);
	}
}
