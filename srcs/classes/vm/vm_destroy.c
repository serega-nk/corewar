/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:38:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/28 19:01:53 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

void	vm_destroy(t_vm **aself)
{
	if (aself && *aself)
	{
		list_clean((*aself)->new_processes, &process_destroy);
		list_destroy(&(*aself)->new_processes);
		list_clean((*aself)->processes, &process_destroy);
		list_destroy(&(*aself)->processes);
		vector_clean((*aself)->players, &player_destroy);
		vector_destroy(&(*aself)->players);
		ft_memdel((void **)aself);
	}
}
