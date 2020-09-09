/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:47:53 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:59:12 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include "ft_xexit.h"

char	*ft_xprintf(const char *format, ...)
{
	t_parse		self;
	size_t		len;

	ft_bzero(&self, sizeof(t_parse));
	if (format)
	{
		self.fd = -1;
		self.format = format;
		va_start(self.ap, format);
		ft_pf_parse_while(&self);
		va_end(self.ap);
		len = self.result;
		ft_bzero(&self, sizeof(t_parse));
		self.fd = -1;
		self.format = format;
		self.str = ft_xmemalloc(len + 1);
		self.n = len;		
		va_start(self.ap, format);
		ft_pf_parse_while(&self);
		va_end(self.ap);
	}
	return (self.str);	
}
