# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 11:18:31 by wben-sai          #+#    #+#              #
#    Updated: 2021/10/16 17:13:48 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

SRC = main.cpp mutantstack.cpp

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o ex02
clean:
	rm -rf ex02
fclean:
	rm -rf ex02
re: fclean all