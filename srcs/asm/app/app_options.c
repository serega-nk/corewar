/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 02:07:36 by jremarqu         ###   ########.fr       */
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

static void		print_usage(char *name)
{
	ft_printf("\n");
	ft_printf("====================================================\n");
	ft_printf("Usage: %s [-b -h -i -l -t] <sourcefile.s><...>\n", name);
	ft_printf("====================================================\n");
	ft_printf("	-b: Show byte code\n");
	ft_printf("	-h: Show usage\n");
	ft_printf("	-i: Show introduction of instruction\n");
	ft_printf("	-l: Show labels\n");
	ft_printf("	-t: Show tokens\n");
	ft_printf("====================================================\n");
	ft_printf("\n");
	ft_xexit(EXIT_SUCCESS);
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
		print_usage(name);
	}
	self->multi = self->argc != 1;
}
