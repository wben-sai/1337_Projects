# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 08:57:42 by wben-sai          #+#    #+#              #
#    Updated: 2021/09/27 14:42:48 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o ScavTrap
clean:
	rm -rf ScavTrap
fclean:
	rm -rf ScavTrap
re: fclean all
