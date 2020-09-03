/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compiler_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 17:08:33 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/03 21:20:45 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_close(int *afd)
{
	if (*afd >= 3)
		close(*afd);
	*afd = -1;
}

void		compiler_destroy(t_compiler **aself)
{
	if (aself && *aself)
	{
		ft_close(&(*aself)->output_fd);
		ft_close(&(*aself)->source_fd);
		ft_strdel(&(*aself)->outputfile);
		ft_memdel((void **)aself);
	}
}
