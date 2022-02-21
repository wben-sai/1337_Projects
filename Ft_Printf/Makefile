# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 19:39:20 by wben-sai          #+#    #+#              #
#    Updated: 2019/12/13 20:19:35 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils2.c ft_printf_utils4.c ft_printf_utils6.c print_conversion_d.c print_conversion_d3.c print_conversion_d4.c print_conversion_mx2.c print_conversion_mx4.c print_conversion_p.c print_conversion_s.c print_conversion_s2.c print_conversion_u2.c print_conversion_u4.c print_conversion_x.c print_conversion_x2.c print_conversion_x3.c print_conversion_x4.c ft_printf_utils.c ft_printf_utils3.c ft_printf_utils5.c print_conversion_c.c print_conversion_d2.c print_conversion_mx.c print_conversion_mx3.c print_conversion_por.c print_conversion_u.c print_conversion_u3.c

TST = ft_printf.o ft_printf_utils2.o ft_printf_utils4.o ft_printf_utils6.o print_conversion_d.o print_conversion_d3.o print_conversion_d4.o print_conversion_mx2.o print_conversion_mx4.o print_conversion_p.o print_conversion_s.o print_conversion_s2.o print_conversion_u2.o print_conversion_u4.o print_conversion_x.o print_conversion_x2.o print_conversion_x3.o print_conversion_x4.o ft_printf_utils.o ft_printf_utils3.o ft_printf_utils5.o print_conversion_c.o print_conversion_d2.o print_conversion_mx.o print_conversion_mx3.o print_conversion_por.o print_conversion_u.o print_conversion_u3.o

all : $(NAME)

$(NAME) : $(TST)
	ar rc $(NAME) $(TST)

$(TST) :
	gcc -Wall -Wextra -Werror -c $(SRC)

clean : 
	rm -rf $(TST)

bonus : re

fclean : clean
	rm -rf $(NAME)

re : fclean all
