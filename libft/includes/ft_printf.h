/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 01:26:08 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/08 12:52:21 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_snprintf(char *str, size_t n, const char *format, ...);
char	*ft_xprintf(const char *format, ...);

#endif
