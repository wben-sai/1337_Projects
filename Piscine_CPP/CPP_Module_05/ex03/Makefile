# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 09:26:06 by wben-sai          #+#    #+#              #
#    Updated: 2021/10/07 12:45:00 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

SRC = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

all : $(NAME)

$(NAME):$(SRC)
	clang++ -Wall -Wextra -Werror $(SRC) -o ex03
clean:
	rm -rf ex03
fclean:
	rm -rf ex03
re: fclean all