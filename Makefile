# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 17:03:57 by akhodara          #+#    #+#              #
#    Updated: 2023/06/09 17:11:59 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
RM = rm -f
MAKE = make
READLINE = -L ~/.brew/opt/readline/lib -lreadline
CFLAGS = -Wall -Werror -Wextra -I ~/.brew/opt/readline/include -g3
DEBUG = -g3 -fsanitize=address


SRCS =	$(shell find . -name "*.c" -type f)

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -s all -C libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(READLINE) -o $(NAME)
	

clean:
	@clear
	@$(RM) $(OBJS)
	@$(MAKE) clean -C libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) libft/libft.a

re: fclean all

.PHONY: all re clean fclean