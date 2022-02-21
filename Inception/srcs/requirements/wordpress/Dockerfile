FROM debian:buster

RUN apt update
RUN apt-get install -y wget unzip lsb-release gnupg php7.3-fpm php-mysql
RUN apt install -y php-curl php-gd php-mbstring php-xml php-xmlrpc php-soap php-intl php-zip
RUN apt -y install php-fpm
RUN apt -y install curl
RUN apt-get update
RUN wget https://wordpress.org/latest.tar.gz 
RUN tar -xzvf latest.tar.gz
RUN mkdir -p var/www/html/
COPY tools/start.sh /
RUN chmod 777 start.sh
COPY conf/www.conf  /etc/php/7.3/fpm/pool.d/www.conf
COPY conf/php-fpm.conf /etc/php/7.3/fpm/

COPY tools/wp-config.php /wordpress

CMD ["sh" ,"start.sh"]
