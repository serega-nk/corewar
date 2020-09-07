/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:46:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 23:25:07 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H

# include <fcntl.h>

# include "ft_printf.h"
# include "ft_xexit.h"
# include "libft.h"
# include "op.h"

typedef struct s_decompiler		t_decompiler;
typedef struct s_app			t_app;

struct			s_decompiler
{
	char			*bytecode_fn;
	int				bytecode_fd;
	char			*bytecode_data;
	size_t			bytecode_size;
};

struct			s_app
{
	t_bool			error;
	int				argc;
	char			**argv;
	t_bool			option_h;
	t_decompiler	*decompiler;
};

t_decompiler	*decompiler_create(char *bytecode_fn);
void			decompiler_destroy(t_decompiler **aself);

void			app_init(t_app *self, int argc, char *argv[]);
void			app_options(t_app *self);
void			app_execute(t_app *self);
void			app_free(t_app *self);

#endif
