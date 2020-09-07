/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:46:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:05:44 by bconchit         ###   ########.fr       */
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

struct		s_decompiler
{
	char	*bytecode_fn;
	int		bytecode_fd;
	char	*bytecode_data;
	size_t	bytecode_size;
};

#endif
