# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 13:24:53 by wben-sai          #+#    #+#              #
#    Updated: 2021/09/15 11:53:07 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphine

SRC = megaphine.cpp

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o megaphine
clean:
	rm -rf megaphine
fclean:
	rm -rf megaphine
re: fclean all
