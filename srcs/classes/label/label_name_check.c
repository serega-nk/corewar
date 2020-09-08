/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_name_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 20:30:27 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:31:30 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	label_name_check(char *name)
{
	while (*name)
	{
		if (ft_strchr(LABEL_CHARS, (int)*name) == NULL)
			return (FALSE);
		name++;
	}
	return (TRUE);
}
