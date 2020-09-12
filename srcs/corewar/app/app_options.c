/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:20:15 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/12 12:31:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// static t_bool	app_options_parse(t_app *self, char *str)
// {
// 	if (ft_strequ(str, "-h"))
// 	{
// 		self->option_h = TRUE;
// 		return (FALSE);
// 	}
// 	if (ft_strequ(str, "-dump"))
// 	{

// 	}
// 	while (*str)
// 	{
// 		if (*str == 'h')
// 		{
// 			self->option_h = TRUE;
// 			return (FALSE);
// 		}
// 		else
// 		{
// 			ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
// 			ft_xexit(EXIT_FAILURE);
// 		}
// 		str++;
// 	}
// 	return (TRUE);
// }

static char		*app_options_next(t_app *self)
{
	
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
		if (ft_strequ(*self->argv, "-h"))
 		{
 			self->option_h = TRUE;
 			break ;
 		}
		if (ft_strequ(*self->argv, "-dump"))
		{
			self->argc--;
			self->argv++;
			self->option_dump = TRUE;
			str = self->argv;
			if (!parse_int(&str, &self->nbr_cycles) || !parse_none(&str))
			{
				ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
				ft_xexit(EXIT_FAILURE);
			}
		}
		else
			break ;	
		self->argc--;
		self->argv++; 
	}
	// {
	// 	str = *self->argv;
	// 	if (str == NULL || str[0] != '-' || ft_strequ(str, "-"))
	// 		break ;
	// 	self->argc--;
	// 	self->argv++;
	// 	if (ft_strequ(str, "--"))
	// 		break ;
	// 	if (app_options_parse(self, str + 1) == FALSE)
	// 		break ;
	// }
	if (self->argc == 0 || self->option_h)
	{
		ft_printf(
			"Usage: %s [-dump nbr_cycles] [[-n number] champion1.cor] ...\n",
			name);
		ft_xexit(EXIT_SUCCESS);
	}
}
