/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 02:44:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 19:18:55 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_long(char **addr, long *avalue)
{
	char			*ptr;
	unsigned long	value;
	int				negative;

	ptr = *addr;
	negative = (*ptr == '-') ? 1 : 0;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	if (ft_isdigit(*ptr))
	{
		if (*ptr == '0' && ft_isdigit(*(ptr + 1)))
			return (FALSE);
		value = 0;
		while (ft_isdigit(*ptr))
		{
			value = value * 10 + (*ptr++ - '0');
			if ((long)(value - negative) < 0)
				return (FALSE);
		}
		*addr = ptr;
		*avalue = (long)(value * (negative ? -1 : 1));
		return (TRUE);
	}
	return (FALSE);
}
