/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 01:28:51 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/06 01:31:16 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_hex(unsigned char x)
{
	ft_putchar("0123456789abcdef"[x / 16]);
	ft_putchar("0123456789abcdef"[x % 16]);
}

static void		part_pos(char *pos)
{
	size_t		index;

	index = 4;
	while (index-- > 0)
	{
		print_hex(pos[index]);
	}
}

static void		part_hex(unsigned char *ptr, size_t size)
{
	size_t		index;

	index = 0;
	while (index < 16)
	{
		if (index < size)
			print_hex(ptr[index]);
		else
			ft_putstr("  ");
		if (index % 2)
			ft_putstr(" ");
		index++;
	}
}

static void		part_txt(unsigned char *ptr, size_t size)
{
	size_t		index;

	index = 0;
	while (index < 16 && index < size)
	{
		ft_putchar(ptr[index] >= 32 && ptr[index] < 127 ? ptr[index] : '.');
		index++;
	}
}

void			ft_print_memory(const void *addr, size_t size)
{
	size_t	pos;

	pos = 0;
	while (pos < size)
	{
		part_pos((char *)&pos);
		ft_putstr(": ");
		part_hex((unsigned char *)(addr + pos), size - pos);
		ft_putstr(" ");
		part_txt((unsigned char *)(addr + pos), size - pos);
		ft_putstr("\n");
		pos += 16;
	}
}
