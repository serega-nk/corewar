/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 23:43:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/13 18:49:04 by bconchit         ###   ########.fr       */
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
	size_t	pos;
};

void		vector_clean(t_vector *self, void (*delf)());
t_vector	*vector_create(void);
void		vector_destroy(t_vector **aself);
void		vector_resize(t_vector *self, size_t capacity);
t_bool		vector_get(t_vector *self, size_t index, void **adata);
t_bool		vector_pop_back(t_vector *self, void **adata);
void		vector_push_back(t_vector *self, void *data);
void		vector_start(t_vector *self);
void		vector_loop(t_vector *self);
void		vector_eof(t_vector *self);
void		vector_move(t_vector *self, int rel);
t_bool		vector_next(t_vector *self, void **adata);
t_bool		vector_peek(t_vector *self, int rel, void **adata);

#endif
