/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deparser_errorf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:17:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/11 16:17:01 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes.h"

t_bool	deparser_errorf(t_deparser *self, char *message)
{
	deparser_error(self, message);
	ft_strdel(&message);
	return (FALSE);
}
