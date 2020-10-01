/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 01:41:48 by bconchit          #+#    #+#             */
/*   Updated: 2020/10/01 19:14:12 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_H
# define CLASSES_H

# include <fcntl.h>

# include "ft_printf.h"
# include "hashtab.h"
# include "libft.h"
# include "list.h"
# include "parse.h"
# include "vector.h"

# include "op.h"

typedef enum e_token_type		t_token_type;

typedef struct s_token			t_token;
typedef struct s_label			t_label;
typedef struct s_argument		t_argument;
typedef struct s_instruction	t_instruction;
typedef struct s_lexer			t_lexer;
typedef struct s_parser			t_parser;
typedef struct s_compiler		t_compiler;
typedef struct s_deparser		t_deparser;
typedef struct s_decompiler		t_decompiler;

typedef enum e_verbosity		t_verbosity;

typedef struct s_player			t_player;
typedef struct s_process		t_process;
typedef struct s_vm				t_vm;

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
	char			*repr;
};

struct			s_label
{
	t_token			*token;
	char			*name;
	int				index;
	size_t			offset;
	char			*repr;
};

struct			s_argument
{
	t_token			*token;
	t_arg_type		arg_type;
	long			number;
	t_label			*label;
	size_t			size;
	char			*repr;
};

struct			s_instruction
{
	t_token			*token;
	t_op			*op;
	t_arg_type		*arg_types;
	t_vector		*arguments;
	size_t			offset;
	size_t			size;
	char			*bytecode;
	char			*repr;
	char			*sourcecode;
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
	t_bool			error;
	char			*error_message;
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
	t_bool			error;
	char			*error_message;
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
	t_bool			error;
	char			*error_message;
};

struct			s_deparser
{
	char			*data;
	size_t			size;
	size_t			pos;
	t_header		header;
	t_vector		*instructions;
	t_bool			error;
	char			*error_message;
};

struct			s_decompiler
{
	char			*bytecode_fn;
	int				bytecode_fd;
	char			*bytecode_data;
	size_t			bytecode_size;
	t_deparser		*deparser;
	t_vector		*lines;
	t_bool			error;
	char			*error_message;
};

enum			e_verbosity
{
	VERBOSITY_CYCLES = 1,
	VERBOSITY_OPERATIONS = 2,
	VERBOSITY_DEATHS = 4,
};

struct			s_player
{
	int				id;
	char			*name;
	char			*comment;
	char			*data;
	size_t			size;
	int				fd;
	t_bool			error;
	char			*error_message;
};

struct			s_process
{
	t_vm			*vm;
	t_player		*player;
	int				reg[REG_NUMBER + 1];
	t_bool			carry;
	long			pc;
	long			step;
	long			last_live;
	int				cycles_wait;
	t_op			*op;
	t_vector		*arguments;
	t_arg_type		arg_types[MAX_ARG_TYPES];
	int				args[MAX_ARG_TYPES];
	int				id;
};

struct			s_vm
{
	t_vector		*files;
	long			nbr_cycles;
	size_t			octets_per_line;
	t_vector		*players;
	t_list			*processes;
	t_list			*fork_processes;
	unsigned char	mem[MEM_SIZE];
	long			cycles_num;
	long			cycles_to_die;
	long			cycles_after_check;
	long			checks_num;
	long			lives_num;
	t_player		*winner;
	int				process_nbr;
	t_verbosity		verbosity;
};

t_token			*token_create(t_token_type type, int ln, int col);
void			token_destroy(t_token **aself);
char			*token_repr(t_token *self);

t_bool			label_name_check(char *name);
t_label			*label_create(t_token *token, char *name, int index);
void			label_destroy(t_label **aself);
char			*label_repr(t_label *self);

t_argument		*argument_create(void);
void			argument_destroy(t_argument **aself);
size_t			argument_calc_size(t_argument *self, t_bool dir_ind);
char			*argument_repr(t_argument *self);

t_instruction	*instruction_create(void);
void			instruction_destroy(t_instruction **aself);
size_t			instruction_calc_size(t_instruction *self);
void			instruction_make_bytecode(t_instruction *self);
char			*instruction_repr(t_instruction *self);
char			*instruction_sourcecode(t_instruction *self);

t_lexer			*lexer_create(char *input, size_t length);
void			lexer_destroy(t_lexer **aself);
t_bool			lexer_error(t_lexer *self, t_token *token, char *message);
t_bool			lexer_errorf(t_lexer *self, t_token *token, char *message);
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
t_bool			parser_error(t_parser *self, t_token *token, char *message);
t_bool			parser_errorf(t_parser *self, t_token *token, char *message);
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
t_bool			compiler_error(t_compiler *self, char *message);
t_bool			compiler_errorf(t_compiler *self, char *message);
t_bool			compiler_make(t_compiler *self);
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

t_deparser		*deparser_create(char *data, size_t size);
void			deparser_destroy(t_deparser **aself);
t_bool			deparser_eof(t_deparser *self);
t_bool			deparser_error(t_deparser *self, char *message);
t_bool			deparser_errorf(t_deparser *self, char *message);
t_bool			deparser_make(t_deparser *self);
void			deparser_move(t_deparser *self, int rel);
t_bool			deparser_next(t_deparser *self, void *ptr, size_t size);
t_bool			deparser_peek(t_deparser *self, int rel, void *ptr,
	size_t size);
t_bool			deparser_make_header(t_deparser *self);
t_bool			deparser_make_instructions(t_deparser *self);
t_bool			deparser_next_arg_types(t_deparser *self,
	t_instruction *instruction);
t_bool			deparser_next_argument(t_deparser *self,
	t_instruction *instruction, size_t index);
t_bool			deparser_next_instruction(t_deparser *self);
t_bool			deparser_next_op(t_deparser *self, t_instruction *instruction);

t_decompiler	*decompiler_create(char *bytecode_fn);
void			decompiler_destroy(t_decompiler **aself);
t_bool			decompiler_error(t_decompiler *self, char *message);
t_bool			decompiler_errorf(t_decompiler *self, char *message);
t_bool			decompiler_make(t_decompiler *self);
t_bool			decompiler_make_deparser(t_decompiler *self);
t_bool			decompiler_make_lines(t_decompiler *self);
t_bool			decompiler_make_load(t_decompiler *self);

t_player		*player_create(int id);
void			player_destroy(t_player **aself);
t_bool			player_load(t_player *self, char *path);
t_bool			player_error(t_player *self, char *message);
t_bool			player_errorf(t_player *self, char *message);

t_process		*process_create(t_vm *vm, t_player *player, long pc);
void			process_destroy(t_process **aself);
t_process		*process_clone(t_process *parent, long pc);
void			process_step(t_process *self, long rel);
void			process_move(t_process *self);
int				process_get(t_process *self, t_arg_type type, int value);
int				process_read(t_process *self, long rel);
int				process_lget(t_process *self, t_arg_type type, int value);
int				process_lread(t_process *self, long rel);
void			process_write(t_process *self, long rel, int value);
t_bool			process_opcode(t_process *self);
t_bool			process_arg_types(t_process *self);
t_bool			process_arguments(t_process *self);
t_bool			process_validate(t_process *self);
void			process_execute(t_process *self);
void			process_execute_live(t_process *self, int v[3]);
void			process_execute_ld(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_st(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_add(t_process *self, int v[3]);
void			process_execute_sub(t_process *self, int v[3]);
void			process_execute_and(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_or(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_xor(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_zjmp(t_process *self, int v[3]);
void			process_execute_ldi(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_sti(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_fork(t_process *self, int v[3]);
void			process_execute_lld(t_process *self, int v[3], t_arg_type t[3]);
void			process_execute_lldi(t_process *self, int v[3],
	t_arg_type t[3]);
void			process_execute_lfork(t_process *self, int v[3]);
void			process_execute_aff(t_process *self, int v[3]);

t_vm			*vm_create(t_vector *files, t_verbosity verbosity,
	long nbr_cycles, size_t octets_per_line);
void			vm_destroy(t_vm **aself);
void			vm_run(t_vm *self);
void			vm_load(t_vm *self);
void			vm_start(t_vm *self);
void			vm_intro(t_vm *self);
void			vm_loop(t_vm *self);
void			vm_final(t_vm *self);
void			vm_dump(t_vm *self);
void			vm_next(t_vm *self);
void			vm_check(t_vm *self);
void			vm_write(t_vm *self, long pos, void *data, size_t size);
void			vm_read(t_vm *self, long pos, void *data, size_t size);

#endif
