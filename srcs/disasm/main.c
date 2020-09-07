/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:33:31 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:48:47 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int		main(int argc, char *argv[])
{
	t_app	app;

	app_init(&app, argc, argv);
	app_options(&app);
	app_execute(&app);
	app_free(&app);
	return (app.error == FALSE ? EXIT_SUCCESS : EXIT_FAILURE);
}
