/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_usage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:06:18 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 19:02:51 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	app_options_usage(t_app *self)
{
	if (self->argc == 0)
	{
		ft_printf("=================================================="
		"==============================================\n");
		ft_printf("Usage: ./corewar [-v <num> -dump <num>"
		" -d <num> -n <num>] champion.cor> <...>\n\n");
		ft_printf("\t-v\t <num> :\tPrint output from \"aff\""
							"(Default is off)\n");
		ft_printf("\t\t\t\t\t- 0 : Show cycles\t\n");
		ft_printf("\t\t\t\t\t- 1 : Show operations\t\n");
		ft_printf("\t\t\t\t\t- 2 : Show deaths\t\n");
		ft_printf("\t-dump\t <num> :\tDump memory (32 octets per line)"\
							" after <num> cycles and exit\n");
		ft_printf("\t-d\t <num> :\tDump memory (64 octets per line)"\
							" after <num> cycles and exit\n");
		ft_printf("\t-n\t <num> :\tSet <num> of the next player\n");
		ft_printf("=================================================="
		"==============================================\n");
		ft_xexit(EXIT_SUCCESS);
	}
}
