# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 19:39:20 by wben-sai          #+#    #+#              #
#    Updated: 2019/10/27 18:38:20 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c ft_lstlast_bonus.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c ft_lstnew_bonus.c ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_lstsize_bonus.c ft_putendl_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c ft_lstadd_back_bonus.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c ft_toupper.c ft_calloc.c ft_lstadd_front_bonus.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c libft.h ft_isalnum.c ft_lstclear_bonus.c ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_lstdelone_bonus.c ft_memcpy.c ft_strchr.c ft_strnstr.c ft_isascii.c ft_lstiter_bonus.c ft_memmove.c ft_strdup.c ft_strrchr.c ft_lstmap_bonus.c

TST = ft_atoi.o ft_isprint.o ft_lstlast_bonus.o ft_memmove.o ft_strchr.o ft_strncmp.o ft_bzero.o ft_itoa.o ft_lstnew_bonus.o ft_memset.o ft_strdup.o ft_strnstr.o ft_calloc.o ft_lstadd_back_bonus.o ft_lstsize_bonus.o ft_putchar_fd.o ft_strjoin.o ft_strrchr.o ft_isalnum.o ft_lstadd_front_bonus.o ft_memccpy.o ft_putendl_fd.o ft_strlcat.o ft_strtrim.o ft_isalpha.o ft_lstclear_bonus.o ft_memchr.o ft_putnbr_fd.o ft_strlcpy.o ft_substr.o ft_isascii.o ft_lstdelone_bonus.o ft_memcmp.o ft_putstr_fd.o ft_strlen.o ft_tolower.o ft_isdigit.o ft_lstiter_bonus.o ft_memcpy.o ft_split.o ft_strmapi.o ft_toupper.o ft_lstmap_bonus.o

all : $(NAME)

$(NAME) : $(TST)
	ar rc $(NAME) $(TST)

$(TST) :
	gcc -Wall -Wextra -Werror -c $(SRC)

clean : 
	rm -rf $(TST)

bonus: all

fclean : clean
	rm -rf $(NAME)

re : fclean all
