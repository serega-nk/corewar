/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 04:41:00 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 23:20:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strndup(const char *src, size_t maxsize)
{
	char		*dst;
	size_t		len;

	len = ft_strnlen(src, maxsize);
	ft_printf("len = %d, maxsize = %d\n", len, maxsize);
	dst = ft_strnew(len);
	if (dst)
		ft_strncpy(dst, src, len);
	return (dst);
}
