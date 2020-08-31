/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 02:44:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 07:34:08 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_bool	parse_int(char **addr, int *avalue)
{
	char	*ptr;
	long	value;
	int		negative;

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
			if ((int)(value - negative) != (value - negative))
				return (FALSE);
		}
		*addr = ptr;
		*avalue = (int)(value * (negative ? -1 : 1));
		return (TRUE);
	}
	return (FALSE);
}
