# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <bconchit@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 20:00:06 by bconchit          #+#    #+#              #
#    Updated: 2020/08/14 18:50:43 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= asm

INC_DIR		= ./includes
SRC_DIR		= ./srcs
OBJ_DIR		= ./objs

HEADERS		= asm.h
SOURCES		= \
	$(addprefix asm/, \
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
			parser_create.c \
			parser_destroy.c \
		) \
		$(addprefix token/, \
			token_create.c \
			token_destroy.c \
			token_print.c \
		) \
		main.c \
	) \
	$(addprefix vector/, \
		vector_clean.c \
		vector_create.c \
		vector_destroy.c \
		vector_get.c \
		vector_next.c \
		vector_pop_back.c \
		vector_push_back.c \
		vector_resize.c \
		vector_start.c \
	) \

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)/ -I$(LIBFT_DIR)/includes/
LFLAGS		= -L$(LIBFT_DIR)/ -lft

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(WFLAGS) $(IFLAGS) $(OBJS) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME).dSYM

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME).dSYM
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

vv: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42.s

.PHONY: all clean fclean re norm vv
