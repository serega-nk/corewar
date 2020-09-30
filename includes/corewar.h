/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:07:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/30 11:30:09 by bconchit         ###   ########.fr       */
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
void	app_options_dump(t_app *self);
void	app_options_files(t_app *self);

#endif
