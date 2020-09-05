/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/05 23:15:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		app_options_parse(t_app *self, char *str)
{
	while (*str)
	{
		if (*str == 'b')
			self->option_b = TRUE;
		else if (*str == 'h')
		{
			self->option_h = TRUE;
			return ;
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
		if (str == NULL || str[0] != '-')
			break ;
		self->argc--;
		self->argv++;
		if (ft_strequ(str, "--"))
			break ;
		app_options_parse(self, str + 1);
	}
	if (self->argc == 0 || self->option_h)
	{
		ft_printf("Usage: %s [-bhilt] <sourcefile.s>\n", name);
		ft_xexit(EXIT_SUCCESS);
	}
}
