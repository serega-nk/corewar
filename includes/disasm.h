/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:46:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 01:47:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H

# include <fcntl.h>

# include "ft_printf.h"
# include "ft_xexit.h"
# include "libft.h"
# include "classes.h"

typedef struct s_app			t_app;

struct		s_app
{
	t_bool			error;
	int				argc;
	char			**argv;
	t_bool			option_h;
	t_decompiler	*decompiler;
};

void		app_init(t_app *self, int argc, char *argv[]);
void		app_options(t_app *self);
void		app_execute(t_app *self);
void		app_free(t_app *self);

#endif
