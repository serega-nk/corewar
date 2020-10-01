/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:44:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 03:38:39 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		just_case_for_option_files_n(t_app *self, int num)
{
	size_t		index;

	if ((num > 0 && num <= MAX_PLAYERS) == FALSE)
	{
		ft_printf_fd(STDERR_FILENO,
			"Wrong number of the player %ld [1..%ld]\n",
			num, MAX_PLAYERS);
		ft_xexit(EXIT_FAILURE);
	}
	index = (size_t)num - 1;
	if (vector_get2(self->files, index) != NULL)
	{
		ft_printf_fd(STDERR_FILENO, "ERROR Order of players is "\
			"duplicated, num = %d\n", num);
		ft_xexit(EXIT_FAILURE);
	}
	vector_set(self->files, index, self->argv[2]);
	self->argc -= 3;
	self->argv += 3;
}

static t_bool	app_options_files_n(t_app *self)
{
	char		*ptr;
	int			num;

	if (self->argc > 0 && ft_strequ(self->argv[0], "-n"))
	{
		if (self->argc >= 3)
		{
			ptr = self->argv[1];
			if (parse_int(&ptr, &num) &&
				parse_none(&ptr))
			{
				just_case_for_option_files_n(self, num);
				return (TRUE);
			}
		}
		ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
		ft_xexit(EXIT_FAILURE);
	}
	return (FALSE);
}

static t_bool	app_options_files_file(t_app *self)
{
	if (self->argc > 0)
	{
		vector_push_back(self->pending, self->argv[0]);
		self->argc--;
		self->argv++;
		return (TRUE);
	}
	return (FALSE);
}

static void		app_options_files_after(t_app *self)
{
	char	*ptr;
	size_t	index;

	vector_start(self->pending);
	index = 0;
	while (index < self->files->count)
	{
		if (vector_get2(self->files, index) == NULL)
		{
			if (vector_next(self->pending, (void **)&ptr) == FALSE)
			{
				ft_printf_fd(STDERR_FILENO, "ERROR: You cant set order," \
					" not enough players\n");
				ft_xexit(EXIT_FAILURE);
			}
			vector_set(self->files, index, ptr);
		}
		index++;
	}
	while (vector_next(self->pending, (void **)&ptr))
		vector_push_back(self->files, ptr);
	if (self->files->count > MAX_PLAYERS)
		check_to_error_max_plyrs(self);
}

void			app_options_files(t_app *self)
{
	if (self->argc == 0)
	{
		ft_printf_fd(STDERR_FILENO, "Invalid Option\n");
		ft_xexit(EXIT_FAILURE);
	}
	while (app_options_files_n(self) || app_options_files_file(self))
		;
	app_options_files_after(self);
}
