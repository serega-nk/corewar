/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:58:14 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/31 14:01:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	argument_validate(t_argument *argument, t_arg_type arg_type)
{
	if (((argument->arg_type & T_REG) && (argument->arg_type != T_REG)) ||
		((argument->arg_type & T_DIR) && (argument->arg_type & T_IND)) ||
		((argument->arg_type & T_REG) && !(arg_type & T_REG)) ||
		((argument->arg_type & T_DIR) && !(arg_type & T_DIR)) ||
		((argument->arg_type & T_IND) && !(arg_type & T_IND)))
	{
		return (FALSE);
	}
	return (TRUE);
}
