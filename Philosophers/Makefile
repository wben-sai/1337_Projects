# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 13:24:53 by wben-sai          #+#    #+#              #
#    Updated: 2021/07/10 14:39:28 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philosophers.c utilis.c event.c gestion_thread.c

all : $(NAME)

$(NAME):$(SRC)
	gcc -Wall -Wextra -Werror $(SRC) -o philo
clean:
	rm -rf philo
fclean:
	rm -rf philo
re: fclean all
