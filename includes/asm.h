/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 22:41:30 by bconchit          #+#    #+#             */
/*   Updated: 2020/09/07 22:08:14 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>

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

typedef struct s_app			t_app;

enum			e_token_type
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

struct			s_token
{
	t_token_type	type;
	int				ln;
	int				col;
	char			*value;
};

struct			s_label
{
	t_token			*token;
	char			*name;
	int				index;
	size_t			offset;
};

struct			s_instruction
{
	t_token			*token;
	t_op			*op;
	t_vector		*arguments;
	size_t			offset;
	size_t			size;
	char			*bytecode;
};

struct			s_argument
{
	t_token			*token;
	t_arg_type		arg_type;
	long			number;
	t_label			*label;
	size_t			size;
};

struct			s_lexer
{
	char			*input;
	size_t			length;
	size_t			pos;
	size_t			start;
	int				ln;
	int				col;
	t_vector		*tokens;
};

struct			s_parser
{
	t_vector		*tokens;
	size_t			pos;
	char			*cmd_name;
	char			*cmd_comment;
	t_token			*end;
	t_hashtab		*labels;
	t_vector		*instructions;
	t_vector		*convert_labels;
};

struct			s_compiler
{
	t_lexer			*lexer;
	t_parser		*parser;
	t_header		header;
	size_t			prog_size;
	char			*source_fn;
	int				source_fd;
	char			*source_data;
	size_t			source_size;
	char			*bytecode_fn;
	int				bytecode_fd;
	char			*bytecode_data;
	size_t			bytecode_size;
};

struct			s_app
{
	t_bool			error;
	int				argc;
	char			**argv;
	t_bool			option_a;
	t_bool			option_b;
	t_bool			option_h;
	t_bool			option_i;
	t_bool			option_l;
	t_bool			option_t;
	t_compiler		*compiler;
};

char			*token_type_name(t_token_type token_type);

t_token			*token_create(t_token_type type, int ln, int col);
void			token_destroy(t_token **aself);
t_bool			token_error(t_token *self, char *str);
void			token_print(t_token *self);

t_label			*label_create(t_token *token, char *name, int index);
void			label_destroy(t_label **aself);
t_bool			label_name_check(char *name);
void			label_print(t_label *label);

t_argument		*argument_create(void);
void			argument_destroy(t_argument **aself);
void			argument_print(t_argument *self);

t_instruction	*instruction_create(void);
void			instruction_destroy(t_instruction **aself);
size_t			instruction_calc_size(t_instruction *self);
void			instruction_make_bytecode(t_instruction *self);
void			instruction_print(t_instruction *self);

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

t_compiler		*compiler_create(char *source_fn);
void			compiler_destroy(t_compiler **aself);
t_bool			compiler_make(t_compiler *self, t_bool multi);
t_bool			compiler_make_load(t_compiler *self);
t_bool			compiler_make_analyzed(t_compiler *self);
t_bool			compiler_make_prog_size(t_compiler *self);
t_bool			compiler_make_convert_labels(t_compiler *self);
t_bool			compiler_make_header(t_compiler *self);
t_bool			compiler_make_bytecode(t_compiler *self);
t_bool			compiler_make_save(t_compiler *self);
void			compiler_print_tokens(t_compiler *self);
void			compiler_print_labels(t_compiler *self);
void			compiler_print_instructions(t_compiler *self);
void			compiler_print_bytecode(t_compiler *self);

void			app_init(t_app *self, int argc, char *argv[]);
void			app_options(t_app *self);
void			app_bytecodes(t_app *self);
void			app_free(t_app *self);

#endif
