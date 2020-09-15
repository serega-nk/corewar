/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_options_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:44:40 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 18:43:40 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_bool	app_options_files_n(t_app *self)
{
	char		*ptr;
	int			num;
	size_t		index;

	if (self->argc > 0 && ft_strequ(self->argv[0], "-n"))
	{
		if (self->argc >= 3)
		{
			ptr = self->argv[1];
			if (parse_int(&ptr, &num) &&
				parse_none(&ptr))
			{
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
					ft_printf_fd(STDERR_FILENO, "ERROR num = %d\n", num);
					ft_xexit(EXIT_FAILURE);
				}
				vector_set(self->files, index, self->argv[2]);
				self->argc -= 3;
				self->argv += 3;
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
	size_t	count;

	vector_start(self->pending);
	index = 0;
	count = self->files->count;
	while (index < self->files->count)
	{
		if (vector_get2(self->files, index) == NULL)
		{
			if (vector_next(self->pending, (void **)&ptr) == FALSE)
			{
				ft_printf_fd(STDERR_FILENO, "ERROR\n");
				ft_xexit(EXIT_FAILURE);
			}
			vector_set(self->files, index, ptr);
		}
		index++;
	}	
	while (vector_next(self->pending, (void **)&ptr))
		vector_push_back(self->files, ptr);
	if (self->files->count > MAX_PLAYERS)
	{
		ft_printf_fd(STDERR_FILENO,
			"Wrong number of players = %ld (MAX_PLAYERS %ld)\n",
			self->files->count, MAX_PLAYERS);
		ft_xexit(EXIT_FAILURE);
	}
}

void			app_options_files(t_app *self)
{
	while (app_options_files_n(self) || app_options_files_file(self))
		;
	app_options_files_after(self);
}
