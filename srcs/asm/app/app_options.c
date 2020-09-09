/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:40:33 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_bool	app_options_parse(t_app *self, char *str)
{
	while (*str)
	{
		if (*str == 'b')
			self->option_b = TRUE;
		else if (*str == 'h')
		{
			self->option_h = TRUE;
			return (FALSE);
		}
		else if (*str == 'i')
			self->option_i = TRUE;
		else if (*str == 'l')
			self->option_l = TRUE;
		else if (*str == 't')
			self->option_t = TRUE;
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
		ft_printf("Usage: %s [-bhilt] <sourcefile.s>\n", name);
		ft_xexit(EXIT_SUCCESS);
	}
	self->multi = self->argc != 1;
}
