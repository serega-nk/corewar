/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:06:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/09 22:41:23 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int argc, char *argv[])
{
	t_app	app;

	app_init(&app, argc, argv);
	app_options(&app);
	app_execute(&app);
	app_free(&app);
	return (app.errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
