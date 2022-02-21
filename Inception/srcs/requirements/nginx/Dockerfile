FROM debian:buster

RUN apt update
RUN apt install -y nginx openssl curl

COPY tools/sleep.sh /
COPY conf/default /etc/nginx/sites-available
RUN openssl dhparam -out /etc/nginx/dhparam.pem 1024

COPY tools/ssl-nginx.crt /etc/ssl/certs/
COPY tools/ssl-nginx.key /etc/ssl/private/

RUN chmod 777 sleep.sh

CMD ["sh" ,"sleep.sh"]