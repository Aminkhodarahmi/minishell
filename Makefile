# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 17:03:57 by akhodara          #+#    #+#              #
#    Updated: 2023/06/19 15:55:13 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME = minishell
CC = gcc
RM = rm -f
MAKE = make
READLINE = -L ~/.brew/opt/readline/lib -lreadline
CFLAGS = -Wall -Werror -Wextra -I ~/.brew/opt/readline/include -g3

# SOURCES & OBJECTS #

SRCS =	src/main.c \
		src/error_msg.c \
		src/read_input.c \
		src/signal.c \
		src/redirections.c \
		src/builtins/cd.c \
		src/builtins/pwd.c \
		src/builtins/echo.c \
		src/builtins/env.c \
		src/builtins/env_list.c \
		src/builtins/export.c \
		src/builtins/unset.c \
		src/builtins/exit.c \
		src/executer/exec_args.c \
		src/executer/exec_cmd.c \
		src/executer/pipes.c \
		src/executer/args_list.c \
		src/executer/here_doc.c \
		src/lexer/check_args.c \
		src/lexer/expand.c \
		src/lexer/expand_aux.c \
		src/lexer/quotes.c \
		src/lexer/split_args.c \
		src/lexer/token.c \
		src/lexer/check_error_pipes.c \

OBJS = $(SRCS:.c=.o)

# RULES #

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft/libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft/libft.a $(READLINE) -o $(NAME)

clean:
	@clear
	@$(RM) $(OBJS)
	@$(MAKE) clean -C ./libft/libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./libft/libft/libft.a

re: fclean all

.PHONY: all re clean fclean test
