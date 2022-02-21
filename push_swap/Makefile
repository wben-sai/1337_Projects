# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 17:22:10 by wben-sai          #+#    #+#              #
#    Updated: 2021/06/30 20:02:58 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c utilis.c s.c r.c rr.c p.c stack.c sort.c gestion_stack.c push_nbr.c

all : $(NAME)

$(NAME):$(SRC)
	gcc -Wall -Wextra -Werror $(SRC) -o push_swap
clean:
	rm -rf push_swap
fclean:
	rm -rf push_swap
re: fclean all
