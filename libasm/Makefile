# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/10 13:00:10 by wben-sai          #+#    #+#              #
#    Updated: 2021/01/01 15:55:33 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm

SRC = ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s

TST = ft_read.o ft_strcmp.o ft_strcpy.o ft_strdup.o ft_strlen.o ft_write.o

all : $(NAME)

$(NAME) : $(SRC)
	nasm -f macho64 ft_read.s 
	nasm -f macho64 ft_strcmp.s 
	nasm -f macho64 ft_strcpy.s 
	nasm -f macho64 ft_strdup.s 
	nasm -f macho64 ft_strlen.s 
	nasm -f macho64 ft_write.s
	ar rc $(NAME) $(TST)
	
clean : 
	rm -rf $(TST)

bonus: all

fclean : clean
	rm -rf $(NAME)

re : fclean all
