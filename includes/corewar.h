/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:07:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 06:32:27 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>

# include "ft_printf.h"
# include "ft_xexit.h"
# include "libft.h"
# include "hashtab.h"
# include "vector.h"

# include "classes.h"

typedef struct s_app	t_app;

struct	s_app
{
	char			*name;
	int				argc;
	char			**argv;
	long			nbr_cycles;
	t_verbosity		verbosity;
	t_bool			option_d;
	t_vector		*pending;
	t_vector		*files;
	t_vm			*vm;
	int				error;
};

void	app_init(t_app *self, int argc, char *argv[]);
void	app_options(t_app *self);
void	app_execute(t_app *self);
void	app_free(t_app *self);

void	app_options_usage(t_app *self);
t_bool	app_options_verbosity(t_app *self);
t_bool	app_options_dump(t_app *self);
void	app_options_files(t_app *self);

/*
**	check_to_error_max_plyrs(t_app *self) is the special func
**	for app_optioms_files.c wich we use in
**	static void		app_options_files_after(t_app *self) func
**
**	Way to the place: --> srcs/corewar/app/options/app_options_files.c
*/

void	check_to_error_max_plyrs(t_app *self);

#endif
