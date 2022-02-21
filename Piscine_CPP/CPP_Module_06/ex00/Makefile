# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 16:30:37 by wben-sai          #+#    #+#              #
#    Updated: 2021/10/10 16:30:50 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00

SRC = main.cpp cast.cpp

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o ex00
clean:
	rm -rf ex00
fclean:
	rm -rf ex00
re: fclean all
