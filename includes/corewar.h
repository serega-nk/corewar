/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:07:34 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/15 01:22:01 by bconchit         ###   ########.fr       */
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
	t_vector		*args;
	t_bool			option_dump;
	long			nbr_cycles;
	t_vector		*sequence;
	t_vector		*files;
};

void	app_init(t_app *self, int argc, char *argv[]);
void	app_options(t_app *self);
void	app_execute(t_app *self);
void	app_free(t_app *self);

#endif
