/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:41:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/08/05 23:09:44 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "ft_printf.h"
# include "ft_xexit.h"
# include "libft.h"
# include "list.h"
# include "gnl.h"

# include "op.h"

typedef struct s_token		t_token;
typedef struct s_scanner	t_scanner;
typedef struct s_lexer		t_lexer;
typedef struct s_parser		t_parser;
typedef struct s_compiler	t_compiler;

typedef struct s_app		t_app;

struct	s_compiler
{
	char		*text;
	t_lexer		*lexer;
	t_list		*tokens;
	t_parser	*parser;	
};

struct	s_lexer
{
	char	*text;
	size_t	size;
	int		lineno;
	int		column;
};

t_token		*token_create(void);
void		token_destroy(t_token **aself);

t_compiler	*compiler_create(void);
void		compiler_destroy(t_compiler **aself);

t_bool		compiler_make_bytecode(t_compiler *self, char *fn);

// typedef enum e_type		t_type;
// typedef struct s_token	t_token;
// typedef struct s_lexer	t_lexer;

// enum		e_type
// {
// 	UNKNOWN,
// 	COMMAND_NAME,
// 	COMMAND_COMMENT,
// 	STRING,
// 	LABEL,
//  	INSTRUCTION,
//  	REGISTER,
//  	DIRECT,
//  	DIRECT_LABEL,
//  	INDIRECT,
//  	INDIRECT_LABEL,
// 	ENDLINE,
// 	SEPARATOR,
// 	END,
// 	COMMENT,
// 	WHITESPACE,
// };

// struct		s_token
// {
// 	t_type	type;
// 	int		lineno;
// 	int		column;
// 	char	*value;
// };

// struct		s_lexer
// {
// 	char	*data;
// 	size_t	size;
	
// 	size_t	index;
// 	// t_type	type;
// 	// t_list	*tokens;
// };

// t_token		*token_create(void);
// void		token_destroy(t_token **aself);
// const char	*token_type_str(t_token *self);

// t_lexer		*lexer_create(void);
// void		lexer_destroy(t_lexer **aself);


// typedef enum e_type		t_type;

// enum	e_state
// {
// 	STATE_NONE,
// 	STATE_STRING,

// };

// enum	e_type
// {
// 	COMMAND_NAME,
// 	COMMAND_COMMENT,
// 	STRING,
// 	LABEL,
// 	INSTRUCTION,
// 	REGISTER,
// 	DIRECT,
// 	DIRECT_LABEL,
// 	INDIRECT,
// 	INDIRECT_LABEL,
// 	ENDLINE,
// 	SEPARATOR,
// 	END,
// 	COMMENT,
// 	WHITESPACE,
// };

/*
{
const char *v2; // [rsp+10h] [rbp-10h]

switch ( (unsigned __int64)*a1 )
{
case 0uLL:
v2 = "COMMAND_NAME";
break;
case 1uLL:
v2 = "COMMAND_COMMENT";
break;
case 2uLL:
v2 = "STRING";
break;
case 3uLL:
v2 = "LABEL";
break;
case 4uLL:
v2 = "INSTRUCTION";
break;
case 5uLL:
v2 = "REGISTER";
break;
case 6uLL:
v2 = "DIRECT";
break;
case 7uLL:
v2 = "DIRECT_LABEL";
break;
case 8uLL:
v2 = "INDIRECT";
break;
case 9uLL:
v2 = "INDIRECT_LABEL";
break;
case 0xAuLL:
v2 = "ENDLINE";
break;
case 0xBuLL:
v2 = "SEPARATOR";
break;
case 0xCuLL:
v2 = "END";
break;
case 0xDuLL:
v2 = "COMMENT";
break;
case 0xEuLL:
v2 = "WHITESPACE";
break;
case 0xFuLL:
v2 = "program";
break;
case 0x10uLL:
v2 = "header";
break;
case 0x11uLL:
v2 = "command_name_line";
break;
case 0x12uLL:
v2 = "command_comment_line";
break;
case 0x13uLL:
v2 = "code";
break;
case 0x14uLL:
v2 = "line";
break;
case 0x15uLL:
v2 = "rest";
break;
case 0x16uLL:
v2 = "instruction";
break;
case 0x17uLL:
v2 = "parameters";
break;
case 0x18uLL:
v2 = "parameter";
break;
default:
v2 = (const char *)&unk_100012957;
break;
}
return v2;
}
*/

#endif
