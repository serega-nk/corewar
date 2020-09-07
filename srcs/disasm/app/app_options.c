/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 23:24:09 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static t_bool	app_options_parse(t_app *self, char *str)
{
	while (*str)
	{
		if (*str == 'h')
		{
			self->option_h = TRUE;
			return (FALSE);
		}
		else
		{
			ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
			ft_xexit(EXIT_FAILURE);
		}
		str++;
	}
	return (TRUE);
}

void			app_options(t_app *self)
{
	char	*name;
	char	*str;

	name = *self->argv;
	self->argc--;
	self->argv++;
	while (self->argc > 0)
	{
		str = *self->argv;
		if (str == NULL || str[0] != '-' || ft_strequ(str, "-"))
			break ;
		self->argc--;
		self->argv++;
		if (ft_strequ(str, "--"))
			break ;
		if (app_options_parse(self, str + 1) == FALSE)
			break ;
	}
	if (self->argc == 0 || self->option_h)
	{
		ft_printf("Usage: %s [-h] <corfile.cor>\n", name);
		ft_xexit(EXIT_SUCCESS);
	}
}
