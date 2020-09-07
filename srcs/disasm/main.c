/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:33:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 21:58:50 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"


void	test(char *fn)
{
	char	*data;
	size_t	size;
	int		fd;

	fd = open(fn, O_RDONLY);
	if (fd >= 0)
	{
		size = ft_get_size(fd);
		data = ft_xmalloc(size);
		if (ft_readall(fd, data, size))
		{
			
			return ;
		}
	}
	ft_printf("Can't read source file %s", fn);
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
	{
		test(argv[1]);
	}
	return (EXIT_SUCCESS);
}
