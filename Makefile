# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 17:29:05 by ybenoit           #+#    #+#              #
#    Updated: 2016/12/08 20:00:14 by ybenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=fdf
FLAGS=-Wall -Wextra -Werror

LIB_PATH=libft
LIB=$(LIB_PATH)/libft.a
LIB_LINK=-L $(LIB_PATH) -lft

INC_DIR=includes
INCS=-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)

SRC_DIR=srcs
SRC_BASE=main.c\

OBJ_DIR=obj

#PREFIXE
SRCS=$(addprefix $(SRC_DIR)/, $(SRC_BASE))
OBJS=$(addprefix $(OBJ_DIR)/, $(SRC_BASE:.c=.o))

#COLORS
C_NO="\033[00m"
C_OK="\033[35m"
C_GOOD="\033[32m"
C_ERROR="\033[31m"
C_WARN="\033[33m"

#DEBUG
SUCCESS=$(C_GOOD)SUCCESS$(C_NO)
OK=$(C_OK)OK$(C_NO)

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	@$(CC) $(FLAGS) $(INCS) -c -o $@ $<
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean