/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_make_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 21:25:28 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 21:50:25 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	compiler_write_header(t_compiler *self)
{
	t_header	*hdr;

	hdr = &self->header;
	return (
		compiler_write(self, &hdr->magic, sizeof(hdr->magic)) &&
		compiler_write(self, hdr->prog_name, sizeof(hdr->prog_name)) &&
		compiler_write(self, hdr->null, sizeof(hdr->null)) &&
		compiler_write(self, &hdr->prog_size, sizeof(hdr->prog_size)) &&
		compiler_write(self, hdr->comment, sizeof(hdr->comment)) &&
		compiler_write(self, hdr->null, sizeof(hdr->null))
	);
}
