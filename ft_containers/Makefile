# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 09:33:47 by wben-sai          #+#    #+#              #
#    Updated: 2022/01/04 15:23:34 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC = main.cpp 

all : $(NAME)

$(NAME):$(SRC)
	clang++ --std=c++98 -Wall -Wextra -Werror $(SRC) -o a.out
	
clean:
	rm -rf a.out
fclean:
	rm -rf a.out
	
re: fclean all