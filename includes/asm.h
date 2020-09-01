/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:41:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/01 21:08:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "ft_printf.h"
# include "ft_xexit.h"
# include "gnl.h"
# include "hashtab.h"
# include "libft.h"
# include "parse.h"
# include "vector.h"
# include "op.h"

typedef enum e_token_type		t_token_type;

typedef struct s_token			t_token;
typedef struct s_label			t_label;
typedef struct s_instruction	t_instruction;
typedef struct s_argument		t_argument;

typedef struct s_lexer			t_lexer;
typedef struct s_parser			t_parser;
typedef struct s_compiler		t_compiler;

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

struct	s_label
{
	t_token			*token;
	char			*name;
	int				index;
	size_t			offset;
};

struct	s_instruction
{
	t_token			*token;
	t_op			*op;
	t_vector		*arguments;
	size_t			offset;
	size_t			size;
};

struct	s_argument
{
	t_token			*token;
	t_arg_type		arg_type;
	int				number;
	t_label			*label;
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
	t_lexer			*lexer;
	size_t			pos;
	char			*command_name;
	char			*command_comment;
	t_token			*end;
	t_hashtab		*labels;
	t_vector		*instructions;
	t_vector		*convert_labels;
};

struct	s_compiler
{
	t_parser		*parser;
	t_header		header;
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

t_parser		*parser_create(t_lexer *lexer);
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


t_compiler		*compiler_create(t_parser *parser);
void			compiler_destroy(t_compiler **aself);
t_bool			compiler_make(t_compiler *self, char *filename);

#endif
