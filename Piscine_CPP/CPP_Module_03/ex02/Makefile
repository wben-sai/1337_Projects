# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 08:57:42 by wben-sai          #+#    #+#              #
#    Updated: 2021/09/27 15:23:00 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp  FragTrap.cpp 

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o FragTrap
clean:
	rm -rf FragTrap
fclean:
	rm -rf FragTrap
re: fclean all
