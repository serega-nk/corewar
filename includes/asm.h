/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:41:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 16:30:32 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "ft_printf.h"
# include "ft_xexit.h"
# include "gnl.h"
# include "hashtab.h"
# include "libft.h"
# include "list.h"
# include "parse.h"
# include "vector.h"

# include "op.h"

typedef enum e_token_type		t_token_type;

typedef struct s_token			t_token;

typedef struct s_command		t_command;
typedef struct s_label			t_label;
typedef struct s_instruction	t_instruction;
typedef struct s_argument		t_argument;

typedef struct s_lexer			t_lexer;
typedef struct s_parser			t_parser;

enum	e_token_type
{
	TOKEN_TYPE_WORD,
	TOKEN_TYPE_STRING,
	TOKEN_TYPE_COMMENT,
	TOKEN_TYPE_WHITESPACE,
	TOKEN_TYPE_LABEL,
	TOKEN_TYPE_SEPARATOR,
	TOKEN_TYPE_DIRECT,
	TOKEN_TYPE_ENDLINE,
	TOKEN_TYPE_END,
};

struct	s_token
{
	t_token_type	type;
	int				ln;
	int				col;
	char			*value;
};

struct	s_command
{
	t_token			*token;
	char			*name;
	char			*value;
};

struct	s_label
{
	t_token			*token;
	char			*name;
	int				index;
};

struct	s_instruction
{
	t_token			*token;
	t_op			*op;
	t_vector		*arguments;
};

struct	s_argument
{
	t_token			*token;
	t_arg_type		arg_type;
	int				number;
	t_label			label;
};

struct	s_lexer
{
	char			*input;
	size_t			length;
	size_t			pos;
	size_t			start;
	int				ln;
	int				col;
	t_vector		*tokens;
};

struct	s_parser
{
	t_vector		*tokens;
	size_t			pos;
	t_token			*end;
	t_hashtab		*labels;
	t_hashtab		*commands;
	t_vector		*instructions;
	t_vector		*convert_labels;
};

t_token			*token_create(t_token_type type, int ln, int col);
void			token_destroy(t_token **aself);
t_bool			token_error(t_token *self, char *str);

t_label			*label_create(t_token *token, char *name, int index);
void			label_destroy(t_label **aself);
t_bool			label_name_check(char *name);

t_argument		*argument_create(void);
void			argument_destroy(t_argument **aself);

t_instruction	*instruction_create(void);
void			instruction_destroy(t_instruction **aself);

t_lexer			*lexer_create(char *input, size_t length);
void			lexer_destroy(t_lexer **aself);
char			lexer_peek(t_lexer *self, int relative_position);
char			lexer_next(t_lexer *self);
t_bool			lexer_eof(t_lexer *self);
t_token_type	lexer_type(t_lexer *self);
void			lexer_start(t_lexer *self);
char			*lexer_value(t_lexer *self);
t_bool			lexer_tokenize_comment(t_lexer *self, t_token *token);
t_bool			lexer_tokenize_spec(t_lexer *self, t_token *token);
t_bool			lexer_tokenize_string(t_lexer *self, t_token *token);
t_bool			lexer_tokenize_whitespace(t_lexer *self, t_token *token);
t_bool			lexer_tokenize_word(t_lexer *self, t_token *token);
t_bool			lexer_tokenize(t_lexer *self);

t_parser		*parser_create(t_vector *tokens);
void			parser_destroy(t_parser **aself);
t_bool			parser_eof(t_parser *self);
t_token			*parser_peek(t_parser *self, int rel);
void			parser_move(t_parser *self, int rel);
t_bool			parser_accept(t_parser *self, t_token_type type);
t_token			*parser_next(t_parser *self);
t_bool			parser_has_command(t_parser *self);
t_bool			parser_has_instruction(t_parser *self);
t_bool			parser_has_label(t_parser *self);
t_bool			parser_has_skip(t_parser *self);
t_bool			parser_next_argument(t_parser *self,
	t_instruction *instruction, t_arg_type allow);
t_bool			parser_next_arguments(t_parser *self,
	t_instruction *instruction);
t_bool			parser_next_command(t_parser *self);
t_bool			parser_next_instruction(t_parser *self);
t_bool			parser_next_label(t_parser *self);
t_bool			parser_next_skip(t_parser *self);
t_bool			parser_make(t_parser *self);

// typedef struct s_compiler	t_compiler;
// typedef struct s_app		t_app;

// struct	s_lexer
// {
// 	char	*text;
// 	size_t	size;
// 	int		lineno;
// 	int		column;
// };

//t_bool		compiler_make_bytecode(t_compiler *self, char *fn);

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
