# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 17:03:57 by akhodara          #+#    #+#              #
#    Updated: 2023/06/25 15:49:38 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
RM = rm -f
MAKE = make
READLINE = -L ~/.brew/opt/readline/lib -lreadline
CFLAGS = -Wall -Werror -Wextra -I ~/.brew/opt/readline/include -g3

SRCS =	src/main.c src/error_handling/error_msg.c src/init/read_input.c \
		src/signal/signal.c src/init/redirections.c src/builtins/pwd.c \
		src/builtins/cd.c src/builtins/echo.c src/builtins/env.c \
		src/builtins/env_list.c src/builtins/export.c src/executer/exec_args.c \
		src/executer/exec_cmd.c src/builtins/unset.c src/builtins/exit.c \
		src/executer/pipes.c src/executer/args_list.c src/executer/here_doc.c \
		src/lexer/check_args.c src/lexer/expand.c src/lexer/expand_sub.c \
		src/lexer/quotes.c src/lexer/split_args.c \
		src/lexer/token.c src/lexer/check_err_pipe.c \
		src/utils/rm_arr_loc.c src/utils/del_str_pos.c src/utils/fr_arr.c\
		src/utils/ft_lst_free.c src/utils/ft_lst_sort.c src/utils/ft_lstdup.c\
		src/utils/ft_new_node.c src/utils/ft_strjoin3.c src/utils/arr_list.c\
		src/utils/arr_add_back.c src/utils/arr_dup.c src/utils/arr_len.c \
		src/utils/write_arr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

	@echo ""
	@echo ""
	@echo "compiling done. Now you have a big shell 😜"
	@echo ""
	@echo ""
	@echo "Have Written by ***  Amin  &  Rouven  ***"
	@echo ""
	@echo ""
	@curl https://icanhazdadjoke.com
	@echo ""
	@echo ""

$(NAME): $(OBJS)
	@$(MAKE) -s -C ./libft
	@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a $(READLINE) -o $(NAME)

clean:
	@clear
	@$(RM) $(OBJS)
	@$(MAKE) clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./libft/libft.a

re: fclean all

.PHONY: all re clean fclean test
