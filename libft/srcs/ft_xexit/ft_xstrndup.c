/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:25:10 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 18:26:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_xexit_private.h"

char	*ft_xstrndup(const char *src, size_t maxsize)
{
	return ((char *)ft_xcheck((void *)ft_strndup(src, maxsize)));
}
