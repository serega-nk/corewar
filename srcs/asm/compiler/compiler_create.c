/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:07:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/02 23:38:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*make_outputfile(char *sourcefile)
{
	char		*basename;
	char		*outputfile;
	size_t		length;

	basename = ft_xstrdup(sourcefile);
	length = ft_strlen(basename);
	if (length >= 2 && ft_strequ(basename + length - 2, ".s"))
		basename[length - 2] = '\0';
	outputfile = ft_xstrdup2(basename, ".cor");
	ft_strdel(&basename);
	return (outputfile);
}

t_compiler		*compiler_create(char *sourcefile)
{
	t_compiler	*self;

	self = (t_compiler *)ft_xmemalloc(sizeof(t_compiler));
	self->sourcefile = sourcefile;
	self->outputfile = make_outputfile(sourcefile);
	return (self);
}
