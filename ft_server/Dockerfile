# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wben-sai <wben-sai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 16:36:35 by wben-sai          #+#    #+#              #
#    Updated: 2020/01/04 16:32:02 by wben-sai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster
RUN apt-get update
RUN apt-get install -y wget unzip lsb-release gnupg php7.3-fpm php-mysql nginx
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.0/phpMyAdmin-5.0.0-all-languages.zip
RUN unzip phpMyAdmin-5.0.0-all-languages.zip && mv phpMyAdmin-5.0.0-all-languages/ /var/www/html/phpmyadmin
RUN apt-get update
RUN wget http://repo.mysql.com/mysql-apt-config_0.8.13-1_all.deb
RUN echo "mysql-apt-config mysql-apt-config/select-server select mysql-5.7" | /usr/bin/debconf-set-selections
RUN DEBIAN_FRONTEND=noninteractive dpkg --install mysql-apt-config_0.8.13-1_all.deb
RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt install -y mysql-server
RUN wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && mv wordpress/* /var/www/html/
RUN openssl dhparam -out /etc/nginx/dhparam.pem 1024
COPY srcs/default /etc/nginx/sites-available/
COPY srcs/nginx-selfsigned.crt /etc/ssl/certs/
COPY srcs/nginx-selfsigned.key /etc/ssl/private/
COPY srcs/wp-config.php /var/www/html/
COPY srcs/ssl-params.conf /etc/nginx/snippets/
COPY srcs/self-signed.conf /etc/nginx/snippets/
COPY srcs/mysql.sh /var/www/html/
COPY srcs/wpdb.sql /
RUN echo "daemon off;" >> /etc/nginx/nginx.conf
CMD sh /var/www/html/mysql.sh
EXPOSE 80 443