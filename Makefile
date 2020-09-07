# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/09/07 22:48:10 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_A 		= asm
NAME_D 		= disasm

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= asm.h disasm.h op.h

SOURCES_C	= \
	$(addprefix classes/, \
		$(addprefix argument/, \
			argument_create.c \
			argument_destroy.c \
			argument_print.c \
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
			compiler_make.c \
		) \
		$(addprefix decompiler/, \
			decompiler_create.c \
			decompiler_destroy.c \
		) \
		$(addprefix instruction/, \
			instruction_create.c \
			instruction_destroy.c \
			instruction_calc_size.c \
			instruction_make_bytecode.c \
			instruction_print.c \
		) \
		$(addprefix label/, \
			label_create.c \
			label_destroy.c \
			label_name_check.c \
			label_print.c \
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
			parser_make.c \
			parser_move.c \
			parser_next.c \
			parser_peek.c \
		) \
		$(addprefix token/, \
			token_create.c \
			token_destroy.c \
			token_error.c \
			token_print.c \
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
OBJS_C		= $(addprefix $(OBJ_DIR)/, $(SOURCES_C:.c=.o))
OBJS_A		= $(addprefix $(OBJ_DIR)/, $(SOURCES_A:.c=.o))
OBJS_D		= $(addprefix $(OBJ_DIR)/, $(SOURCES_D:.c=.o))

all: $(NAME_A) $(NAME_D)

$(NAME_A): $(LIBFT) $(OBJS_C) $(OBJS_A)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_C) $(OBJS_A) $(LFLAGS) -o $@

$(NAME_D): $(LIBFT) $(OBJS_C) $(OBJS_D)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS_C) $(OBJS_D) $(LFLAGS) -o $@

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

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME_A).dSYM
	rm -rf $(NAME_D).dSYM
	rm -rf $(NAME_A)
	rm -rf $(NAME_D)
	find . -type f -name "*.cor" -delete

re: fclean all

norm:
	@norminette $(INCS) $(SRCS_C) $(SRCS_A) $(SRCS_D)

vv: $(NAME_A)
	#valgrind --leak-check=full --show-leak-kinds=all ./$(NAME_A) ./_res/champs/42.s ./_res/champs/ex.s
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME_A) `find . -type f -name "*.s"`

.PHONY: all clean fclean re norm vv
