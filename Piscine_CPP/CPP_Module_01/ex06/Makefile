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

NAME = karenFilter

SRC = main.cpp Karen.cpp

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o karenFilter
clean:
	rm -rf karenFilter
fclean:
	rm -rf karenFilter
re: fclean all
