/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:41:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:41:36 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "ft_printf.h"
# include "ft_xexit.h"
# include "libft.h"
# include "classes.h"

typedef struct s_app			t_app;

struct		s_app
{
	int				argc;
	char			**argv;
	t_bool			option_a;
	t_bool			option_b;
	t_bool			option_h;
	t_bool			option_i;
	t_bool			option_l;
	t_bool			option_t;
	t_compiler		*compiler;
	t_bool			multi;
	int				errors;
	int				success;
};

void		app_init(t_app *self, int argc, char *argv[]);
void		app_options(t_app *self);
void		app_execute(t_app *self);
void		app_free(t_app *self);

#endif
