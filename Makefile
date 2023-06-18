# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 17:03:57 by akhodara          #+#    #+#              #
#    Updated: 2023/06/17 19:22:47 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = clang
CFLAGS = -Wall -Wextra -Werror -I inc/ -I libft/libft/ -I ~/.brew/opt/readline/include -g3
LIBFT = -L libft/libft -lft -L~/.brew/opt/readline/lib -lreadline
# -L libft/libft -lft ~/.brew/opt/readline/lib -lreadline
HEADER = minishell.h

SRC = $(shell find ./src/ -name "*.c" -type f)

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@make clean -C libft/libft/
	@rm -f $(OBJ)

fclean:
	@make fclean -C libft/libft/
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all







# NAME = minishell
# CC = gcc
# RM = rm -f
# MAKE = make
# READLINE = -L ~/.brew/opt/readline/lib -lreadline
# CFLAGS = -Wall -Werror -Wextra -I ~/.brew/opt/readline/include -g3
# DEBUG = -g3 -fsanitize=address


# SRCS =	$(shell find . -name "*.c" -type f)

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(MAKE) -s all -C libft
# 	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(READLINE) -o $(NAME)
	

# clean:
# 	clear
# 	$(RM) $(OBJS)
# 	$(MAKE) clean -C libft

# fclean: clean
# 	$(RM) $(NAME)
# 	$(RM) libft/libft.a

# re: fclean all

# .PHONY: all re clean fclean