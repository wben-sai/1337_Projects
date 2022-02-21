# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 19:32:10 by wben-sai          #+#    #+#              #
#    Updated: 2021/06/18 20:11:35 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./srcs/.env
SRC = @cd srcs && docker-compose -f docker-compose.yml 
all :
	@sudo chmod 777 /etc/hosts
	@sudo echo "127.0.0.1  " $(DOMAIN_NAME) >> /etc/hosts
	@sudo mkdir -p /home/wben-sai/data/Wordpress
	@sudo mkdir -p /home/wben-sai/data/DB
	${SRC} up
up :
	 ${SRC} up 
start:
	${SRC} start
down:
	 ${SRC} down
ps:
	  ${SRC} ps
