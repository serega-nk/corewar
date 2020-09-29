# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/09/28 22:25:30 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_A 		= asm
NAME_D 		= disasm
NAME_W 		= corewar

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= asm.h classes.h corewar.h disasm.h op.h

SOURCES_C	= \
	$(addprefix classes/, \
		$(addprefix argument/, \
			argument_calc_size.c \
			argument_create.c \
			argument_destroy.c \
			argument_repr.c \
		) \
		$(addprefix compiler/, \
			$(addprefix make/, \
				compiler_make_analyzed.c \
				compiler_make_bytecode.c \
				compiler_make_convert_labels.c \
				compiler_make_header.c \
				compiler_make_load.c \
				compiler_make_prog_size.c \
				compiler_make_save.c \
			) \
			$(addprefix print/, \
				compiler_print_bytecode.c \
				compiler_print_instructions.c \
				compiler_print_labels.c \
				compiler_print_tokens.c \
			) \
			compiler_create.c \
			compiler_destroy.c \
			compiler_error.c \
			compiler_errorf.c \
			compiler_make.c \
		) \
		$(addprefix decompiler/, \
			$(addprefix make/, \
				decompiler_make_deparser.c \
				decompiler_make_lines.c \
				decompiler_make_load.c \
			) \
			decompiler_create.c \
			decompiler_destroy.c \
			decompiler_error.c \
			decompiler_errorf.c \
			decompiler_make.c \
		) \
		$(addprefix deparser/, \
			$(addprefix make/, \
				deparser_make_header.c \
				deparser_make_instructions.c \
			) \
			$(addprefix next/, \
				deparser_next_arg_types.c \
				deparser_next_argument.c \
				deparser_next_instruction.c \
				deparser_next_op.c \
			) \
			deparser_create.c \
			deparser_destroy.c \
			deparser_eof.c \
			deparser_error.c \
			deparser_errorf.c \
			deparser_make.c \
			deparser_move.c \
			deparser_next.c \
			deparser_peek.c \
		) \
		$(addprefix instruction/, \
			instruction_create.c \
			instruction_destroy.c \
			instruction_calc_size.c \
			instruction_make_bytecode.c \
			instruction_repr.c \
			instruction_sourcecode.c \
		) \
		$(addprefix label/, \
			label_create.c \
			label_destroy.c \
			label_name_check.c \
			label_repr.c \
		) \
		$(addprefix lexer/, \
			$(addprefix tokenize/, \
				lexer_tokenize_comment.c \
				lexer_tokenize_spec.c \
				lexer_tokenize_string.c \
				lexer_tokenize_whitespace.c \
				lexer_tokenize_word.c \
			) \
			lexer_create.c \
			lexer_destroy.c \
			lexer_eof.c \
			lexer_error.c \
			lexer_errorf.c \
			lexer_next.c \
			lexer_peek.c \
			lexer_start.c \
			lexer_tokenize.c \
			lexer_type.c \
			lexer_value.c \
		) \
		$(addprefix parser/, \
			$(addprefix has/, \
				parser_has_command.c \
				parser_has_instruction.c \
				parser_has_label.c \
				parser_has_skip.c \
			) \
			$(addprefix next/, \
				parser_next_argument.c \
				parser_next_arguments.c \
				parser_next_command.c \
				parser_next_instruction.c \
				parser_next_label.c \
				parser_next_skip.c \
			) \
			parser_accept.c \
			parser_create.c \
			parser_destroy.c \
			parser_eof.c \
			parser_error.c \
			parser_errorf.c \
			parser_make.c \
			parser_move.c \
			parser_next.c \
			parser_peek.c \
		) \
		$(addprefix player/, \
			player_create.c \
			player_destroy.c \
			player_error.c \
			player_errorf.c \
			player_load.c \
		) \
		$(addprefix process/, \
			$(addprefix execute/, \
				process_execute_add.c \
				process_execute_aff.c \
				process_execute_and.c \
				process_execute_fork.c \
				process_execute_ld.c \
				process_execute_ldi.c \
				process_execute_lfork.c \
				process_execute_live.c \
				process_execute_lld.c \
				process_execute_lldi.c \
				process_execute_or.c \
				process_execute_st.c \
				process_execute_sti.c \
				process_execute_sub.c \
				process_execute_xor.c \
				process_execute_zjmp.c \
			) \
			process_arg_types.c \
			process_arguments.c \
			process_clone.c \
			process_create.c \
			process_destroy.c \
			process_execute.c \
			process_move.c \
			process_opcode.c \
			process_reg_get.c \
			process_validate.c \
		) \
		$(addprefix token/, \
			token_create.c \
			token_destroy.c \
			token_repr.c \
		) \
		$(addprefix vm/, \
			vm_check.c \
			vm_create.c \
			vm_destroy.c \
			vm_dump.c \
			vm_final.c \
			vm_intro.c \
			vm_load.c \
			vm_loop.c \
			vm_next.c \
			vm_read.c \
			vm_run.c \
			vm_start.c \
			vm_write.c \
		) \
	) \
	op.c \

SOURCES_A	= \
	$(addprefix asm/, \
		$(addprefix app/, \
			app_execute.c \
			app_free.c \
			app_init.c \
			app_options.c \
		) \
		main.c \
	) \

SOURCES_D	= \
	$(addprefix disasm/, \
		$(addprefix app/, \
			app_execute.c \
			app_free.c \
			app_init.c \
			app_options.c \
		) \
		main.c \
	) \

SOURCES_W	= \
	$(addprefix corewar/, \
		$(addprefix app/, \
			$(addprefix options/, \
				app_options_dump.c \
				app_options_files.c \
				app_options_usage.c \
			) \
			app_execute.c \
			app_free.c \
			app_init.c \
			app_options.c \
		) \
		main.c \
	) \

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc -g
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)/ -I$(LIBFT_DIR)/includes/
LFLAGS		= -L$(LIBFT_DIR)/ -lft

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS_C		= $(addprefix $(SRC_DIR)/, $(SOURCES_C))
SRCS_A		= $(addprefix $(SRC_DIR)/, $(SOURCES_A))
SRCS_D		= $(addprefix $(SRC_DIR)/, $(SOURCES_D))
SRCS_W		= $(addprefix $(SRC_DIR)/, $(SOURCES_W))
OBJS_C		= $(addprefix $(OBJ_DIR)/, $(SOURCES_C:.c=.o))
OBJS_A		= $(addprefix $(OBJ_DIR)/, $(SOURCES_A:.c=.o))
OBJS_D		= $(addprefix $(OBJ_DIR)/, $(SOURCES_D:.c=.o))
OBJS_W		= $(addprefix $(OBJ_DIR)/, $(SOURCES_W:.c=.o))

all: $(NAME_A) $(NAME_D) $(NAME_W)

$(NAME_A): $(LIBFT) $(OBJS_C) $(OBJS_A)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_C) $(OBJS_A) $(LFLAGS) -o $@

$(NAME_D): $(LIBFT) $(OBJS_C) $(OBJS_D)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_C) $(OBJS_D) $(LFLAGS) -o $@

$(NAME_W): $(LIBFT) $(OBJS_C) $(OBJS_W)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_C) $(OBJS_W) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME_A).dSYM
	rm -rf $(NAME_D).dSYM
	rm -rf $(NAME_W).dSYM

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME_A).dSYM
	rm -rf $(NAME_D).dSYM
	rm -rf $(NAME_W).dSYM
	rm -rf $(NAME_A)
	rm -rf $(NAME_D)
	rm -rf $(NAME_W)
	find . -type f -name "*.cor" -delete

re: fclean all

norm:
	@norminette $(INCS) $(SRCS_C) $(SRCS_A) $(SRCS_D) $(SRCS_W)

vv: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME_A) `find . -type f -name "*.s"`

vv2: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME_D) 2.cor

test: $(NAME_W)
	./corewar -dump $(NUM) batman.cor batman.cor amedvedi.cor > 1.txt
	./_res/vm-linux/corewar -d $(NUM) batman.cor batman.cor amedvedi.cor > 2.txt
	diff 1.txt 2.txt || TRUE

test2: $(NAME_W)
	./corewar batman.cor batman.cor amedvedi.cor

.PHONY: all clean fclean re norm vv
