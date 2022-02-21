# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 13:24:53 by wben-sai          #+#    #+#              #
#    Updated: 2021/09/20 11:17:23 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = app

SRC = main.cpp 

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o app
clean:
	rm -rf app
fclean:
	rm -rf app
re: fclean all
