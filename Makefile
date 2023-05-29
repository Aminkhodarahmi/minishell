# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 17:42:48 by rnauke            #+#    #+#              #
#    Updated: 2023/05/29 17:43:17 by rnauke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_NAME = $(NAME).a
O_NAME = $(NAME).o

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

OBJECTS_DIR = obj
SOURCES_DIR = src

SOURCES = push_swap_main.c
OBJECTS = $(SOURCES:.c=.o)

DIR_SRC = $(addprefix $(SOURCES_DIR)/, $(SOURCES))
DIR_OBJ = $(addprefix $(OBJECTS_DIR)/, $(OBJECTS))

FLAGS = -Wall -Werror -Wextra
ARGS = $(LIBFT) 

# bonus
# BONUS_NAME = $(NAME)_bonus.a

# BONUS_DIR = bonus
# OBJECTS_BONUS_DIR = $(addprefix $(BONUS_DIR)/, $(OBJECTS_DIR))
# SOURCES_BONUS_DIR = $(addprefix $(BONUS_DIR)/, $(SOURCES_DIR))

# SOURCES_BONUS = 
# OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

# DIR_SRC_BNS = $(addprefix $(BONUS_DIR)/, $(addprefix $(SOURCES_DIR)/, $(SOURCES_BONUS)))
# DIR_OBJ_BNS = $(addprefix $(BONUS_DIR)/, $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_BONUS)))

all:  $(LIBFT) $(NAME)

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(DIR_OBJ_BNS)
# 	ar -vcrs $(BONUS_NAME) $(DIR_OBJ_BNS)
	
# $(OBJECTS_BONUS_DIR)/%.o : $(SOURCES_BONUS_DIR)/%.c
# 	mkdir -p $(BONUS_DIR)/$(OBJECTS_DIR)
# 	gcc -o $@ -c $< $(ARGS) $(FLAGS)

$(NAME): $(LIB_NAME)
	gcc -o $(NAME) $(LIB_NAME) $(LIBFT) $(FLAGS)

$(LIB_NAME) : $(DIR_OBJ)
	ar -vcrs $(LIB_NAME) $(DIR_OBJ)

$(OBJECTS_DIR)/%.o : $(SOURCES_DIR)/%.c
	mkdir -p $(OBJECTS_DIR)
	gcc -o $@ -c $< $(FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJECTS_DIR)
	rm -rf $(BONUS_DIR)/$(OBJECTS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -rf $(OBJECTS_DIR)
	rm -rf $(BONUS_DIR)/$(OBJECTS_DIR)
	rm -f $(LIB_NAME) $(BONUS_NAME) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: re fclean clean

re: fclean all
