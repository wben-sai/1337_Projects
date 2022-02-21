# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 19:39:20 by wben-sai          #+#    #+#              #
#    Updated: 2020/12/13 17:32:57 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ./cub3D

SRC = button_click.c gestionsprite.c action_bonus.c function_utils2.c function_utils5.c function_utils6.c gestion_params_and_error2.c gestion_sprite.c get_next_line_utils.c save_img.c cub3d.c function_utils3.c gestion_param.c gestion_params_and_error3.c gestion_sprite_utils.c intersection_h.c function_utils.c function_utils4.c gestion_params_and_error.c gestion_player_wall.c functions_bonus.c get_next_line.c intersection_v.c

all: $(NAME)

$(NAME): $(SRC)
	gcc $(SRC) -Wall -Wextra -Werror -lmlx -framework appkit -framework opengl -o $(NAME)
	
bonus: $(NAME)
	
clean:
	rm -f $(NAME)
	
fclean: clean

re: fclean all
