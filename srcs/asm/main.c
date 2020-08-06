/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:06:43 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/06 23:18:38 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_usage(char *name)
{
	ft_printf("Usage: %s [-a] <sourcefile.s>\n", name);
	ft_printf("    -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output\n");
}

// #include <fcntl.h>

// t_list	*get_file_lines(const char *filename)
// {
// 	int		fd;
// 	t_gnl	*gnl;
// 	char	*line;
// 	t_list	*lines;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_printf_fd(STDERR_FILENO, "Can't read source file %s\n", filename);
// 		return (NULL);
// 	}
// 	lines = list_create();
// 	gnl = gnl_create(fd);
// 	while (gnl_readline(gnl, &line) > 0)
// 		list_push_back(lines, line);
// 	gnl_destroy(&gnl);
// 	close(fd);
// 	return (lines);
// }

// void	lexer_parse_line(t_lexer *self, char *line)
// {

// }


// t_bool		make_bytecode(char *filename)
// {
// 	t_list	*lines;
	
// 	if (!(lines = get_file_lines(filename)))
// 		return (FALSE);

// 	t_list_iter	*iter;
// 	char *line;



// 	iter = list_iter_create(lines);
// 	while (list_iter_next(iter, (void **)&line))
// 	{
// 		token_create()
		
// 		while (*line)
// 		{
// 			if (ft_isspace(*line))

// 			if (*line 
// 		}

// 		ft_printf("|%s|", line);


// 	}
// 	list_iter_destroy(&iter);



// 	list_clean(lines, &ft_strdel);
// 	list_destroy(&lines);
// 	return (TRUE);
// }

// t_bool	test(t_app *self)
// {
// 	if (!lexer_readfile(self->lexer, "42.s"))
// 		return (FALSE);
	
// 	return (TRUE);
// }

// t_bool	make_bytecode(char *fn)
// {
// 	t_asm	*asm;

// 	asm = asm_create();
// 	asm_compiler(asm, fn);
// 	asm_destroy(&asm);

// 	compiler = compiler_create();
// 	compiler_make_bytecode(fn, )
	
// 	if (!(text = get_file_contents(fn)))
// 		return (FALSE);
// 	lexer = lexer_create();	
// 	lexer_input();
// 	tokens = lexer_tokens();

// }

int		main(int argc, char *argv[])
{
	int			ret;
	int			i;
	// t_compiler	*compiler;

	ret = EXIT_SUCCESS;
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			// compiler = compiler_create();
			// if (!compiler_make_bytecode(compiler, argv[i]))
			// 	ret = EXIT_FAILURE;
			// compiler_destroy(&compiler);
		 	i++;
		}
	}
	else
		print_usage(argv[0]);

	ft_printf("|%s|\n", ft_strndup("1234567890", 4));
	return (ret);
}
