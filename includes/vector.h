/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:43:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/13 23:55:29 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "libft.h"
# include "ft_xexit.h"

typedef struct s_vector		t_vector;

struct		s_vector
{
	void	**table;
	size_t	capacity;
	size_t	count;	
};

#endif
