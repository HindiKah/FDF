# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenoit <ybenoit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 21:57:52 by ybenoit           #+#    #+#              #
#    Updated: 2016/11/11 22:07:42 by ybenoit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
ALLDO = *.o
ALLDC = ft_*.c
CCO = gcc -c -Wall -Wextra -Werror
CCC = gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	$(CCO) $(ALLDC)
	ar rc $(NAME) $(ALLDO)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(ALLDO)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all


