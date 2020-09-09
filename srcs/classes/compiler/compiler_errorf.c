/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_errorf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 22:23:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 23:07:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	compiler_errorf(t_compiler *self, char *message)
{
	compiler_error(self, message);
	ft_strdel(&message);
	return (FALSE);
}
